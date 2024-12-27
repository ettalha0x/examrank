#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int sockfd, connfd, max_fd;
socklen_t len;
struct sockaddr_in servaddr, cli;

int ids[100000], count = 0;
char *msgs[100000], buf_r[1024], buf_w[42];

fd_set m, r, w;

void fatal() {
    write(2, "Fatal error\n", 12);
    exit(1);
}

int extract_message(char **buf, char **msg) {
    if (!*buf) return 0;
    char *newline = strchr(*buf, '\n');
    if (newline) {
        *newline = '\0';
        *msg = *buf;
        *buf = strdup(newline + 1);
        if (!*buf) fatal();
        return 1;
    }
    return 0;
}

char *str_join(char *buf, char *add) {
    if (!buf) return strdup(add);
    char *newbuf = realloc(buf, strlen(buf) + strlen(add) + 1);
    if (!newbuf) fatal();
    strcat(newbuf, add);
    return newbuf;
}

void broadcast(int sender, char *msg) {
    for (int fd = 0; fd <= max_fd; fd++)
        if (fd != sender && FD_ISSET(fd, &w))
            send(fd, msg, strlen(msg), 0);
}

void join_client(int fd) {
    max_fd = (fd > max_fd) ? fd : max_fd;
    ids[fd] = count++;
    sprintf(buf_w, "server: client %d just arrived\n", ids[fd]);
    broadcast(fd, buf_w);
    FD_SET(fd, &m);
}

void remove_client(int fd) {
    sprintf(buf_w, "server: client %d just left\n", ids[fd]);
    broadcast(fd, buf_w);
    free(msgs[fd]);
    FD_CLR(fd, &m);
    close(fd);
}

void send_msg(int fd) {
    char *msg = NULL;
    while (extract_message(&msgs[fd], &msg)) {
        sprintf(buf_w, "client %d: ", ids[fd]);
        broadcast(fd, buf_w);
        broadcast(fd, msg);
        free(msg);
    }
}

int main(int ac, char **av) {
    if (ac != 2) {
        write(2, "Wrong number of arguments\n", 26);
        return 1;
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) fatal();

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    servaddr.sin_port = htons(atoi(av[1]));

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) fatal();
    if (listen(sockfd, 0) != 0) fatal();

    FD_ZERO(&m);
    FD_SET(sockfd, &m);
    max_fd = sockfd;

    while (1) {
        r = w = m;
        if (select(max_fd + 1, &r, &w, NULL, NULL) < 0) fatal();

        for (int fd = 0; fd <= max_fd; fd++) {
            if (!FD_ISSET(fd, &r)) continue;

            if (fd == sockfd) {
                len = sizeof(cli);
                connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
                if (connfd >= 0) {
                    join_client(connfd);
                    break;
                }
            } else {
                int ret = recv(fd, buf_r, 1023, 0);
                if (ret <= 0) {
                    remove_client(fd);
                    break;
                }
                buf_r[ret] = 0;
                msgs[fd] = str_join(msgs[fd], buf_r);
                send_msg(fd);
            }
        }
    }
    return 0;
}

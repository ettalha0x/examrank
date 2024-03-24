#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
# include <netinet/in.h>

typedef struct server_info {
    int sockfd;
    struct sockaddr_in addr;
    socklen_t len;
} server;

typedef struct client_info {
    int sockfd;
    int id;
} client;

void fatal_error(char *msg) {
    write(2, msg, strlen(msg));
    write(2, "\n", 1);
    exit(1);
}

server init_server(int port) {
    server server;

    // socket create and verification
    server.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server.sockfd == -1)
        fatal_error("Fatal error");

    //create a sockaddr_in struct and fill it with the server's address
    server.addr.sin_family = AF_INET;
    server.addr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    server.addr.sin_port = htons(port);
    server.len = sizeof(server.addr);

    // bind the socket
    if (bind(server.sockfd, (struct sockaddr *)&server.addr, server.len) == -1)
        fatal_error("Fatal error");
    
    // Now server is ready to listen and verification
    if (listen(server.sockfd, 10) != 0)
        fatal_error("Fatal error");
    return server;
}

int main(int ac, char **av) {
    if (ac != 2)
        fatal_error("Wrong number of arguments");

    server server = init_server(atoi(av[1]));
    client clients[FD_SETSIZE];
    fd_set readfds;
    fd_set writefds;
    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    FD_SET(server.sockfd, &readfds);
    static int id = 0;
    while (1) {
        fd_set readfds_cpy = readfds;
        fd_set writefds_cpy = writefds;
        if (select(FD_SETSIZE, &readfds_cpy, &writefds_cpy, NULL, NULL) == -1)
            fatal_error("select() error");
        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &readfds_cpy)) {
                if (i == server.sockfd) {
                    // accept the data packet from client and verification
                    int new_client = accept(server.sockfd, (struct sockaddr *)&server.addr, &server.len);
                    if (new_client < 0)
                        fatal_error("Fatal error");
                    FD_SET(new_client, &readfds);
                    clients[id].id = id;
                    clients[id].sockfd = new_client;
                    id++;
                } else {
                    char buffer[1024];
                    int n = read(i, buffer, 1024);
                    if (n == 0) {
                        close(i);
                        FD_CLR(i, &readfds);
                    
                    }
                    write(i, "connected", 10);
                }
            }
        }
    }
    return 0;
}
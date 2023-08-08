#include "microshell.h"

int ft_error(char *s)
{
    while (*s)
        write(2, s++, 1);
    return 1;
}

int cd(char **av , int i)
{
    if (i != 2)
        return(ft_error("error: cd: bad arguments\n"));
    else if (chdir(av[1]) == -1)
        return(ft_error("error: cd: cannot change directory to "), ft_error(av[1]), ft_error("\n"));
    return 0;
}

int execute(char **av , char **env, int i)
{
    int fd[2];
    int s;
    int has_pipe = av[i] && !strcmp(av[i], "|");

    if (has_pipe && pipe(fd) == -1)
        ft_error("error: fatal\n");

    int pid = fork();
    if (pid == 0)
    {
        av[i] = 0;
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return ft_error("error: fatal\n");
        execve(*av, av, env);
        return ft_error("error: cannot execute "), ft_error(*av), ft_error("\n"); 
    }
    waitpid(pid, &s, 0);
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return ft_error("error: fatal\n");
    return WIFEXITED(s) && WEXITSTATUS(s);
}

int main (int ac, char **av, char **env)
{
    int i = 0;
    int s = 0;
    if (ac > 1)
    {
        while (av[i] && av[++i])
        {
            av += i;
            i = 0;
            while(av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
                i++;
            if(!strcmp(*av, "cd"))
                s = cd(av, i);
            else if (i)
                s = execute(av, env, i);
        }
    }
    return 0;
}
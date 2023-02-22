#include<unistd.h>

int	count(char *s)
{
	int i = 0;
	int count = 0;
	while (s[i])
	{
		while (s[i] == 32 || (s[i] >= 9 &&  s[i] <= 13))
			i++;
		while (s[i] && !(s[i] == 32) && !(s[i] >= 9 &&  s[i] <= 13))
			i++;
		count++;
	}
	return count;
}

int	main (int ac, char **av)
{
	int	i;
	int	j;
	int	n;

	j = 0;
	i = 0;
	n = 0;
	if (ac == 2)
	{
		n = count(av[1]);
		while (j <= n)
		{
			while (av[1][i] && (av[1][i] == 32 || (av[1][i] >= 9 &&  av[1][i] <= 13)))
				i++;
			while (av[1][i] && !(av[1][i] == 32) && !(av[1][i] >= 9 &&  av[1][i] <= 13))
			{
				write(1, &av[1][i], 1);
				i++;
			}
			if (av[1][i] && !(av[1][i + 1] == '\0') && j != n - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}

#include<unistd.h>

int	used(char c, char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return 1;
		i++;
	}
	return 0;
}
int main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char s[1000];
	if (ac == 3)
	{
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j] && !used(av[2][j], s))
				{
					write(1, &av[2][j], 1);
					s[k++] = av[2][j];
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}

#include<unistd.h>

int main(int ac, char **av)
{
	int i = 1;
	int j = 0;
	if (ac == 1)
		write(1, "\n", 1);
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if ((av[i][j - 1] <= 32 || j == 0) && (av[i][j] >= 'a' && av[i][j] <= 'z'))
				av[i][j] -= 32;
			if ((av[i][j - 1] > 32 && j != 0) && (av[i][j] >= 'A' && av[i][j] <= 'Z'))
				av[i][j] += 32;
			write(1, &av[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

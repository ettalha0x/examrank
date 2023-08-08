#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// int	prime(int	n)
// {
// 	if (n == 0 || n == 1)
// 		return 0;
// 	int i = 2;
// 	while (i < n)
// 	{
// 		if (n % i == 0)
// 			return 0;
// 		i++;
// 	}
// 	return 1;
// }

int main(int ac, char **av)
{
	int i;
	int nb;
	if (ac == 2)
	{
		i = 1;
		nb = atoi(av[1]);
		if (nb == 1)
			printf("1");
		while (nb >= ++i)
		{
			if (nb % i == 0)
			{
				printf("%d", i);
				if (nb == i)
					break ;
				printf("*");
				nb = nb / i;
				i = 1;
			}
		}
	}
	printf("\n");
}

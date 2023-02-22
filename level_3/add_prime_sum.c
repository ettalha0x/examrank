#include<unistd.h>

int	ft_atoi(const char *str)
{
	int res = 0;
	int sign = 1;

	while (*str <= 32)
		str++;
	if (*str == '-')
		sign = -1;
	if ( *str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}
void	putnbr(int n)
{
	if (n <= 9)
	{
		char c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
}

int	prime(int n)
{
	int i = 2;
	if (n == 0 || n == 1)
		return 0;
	while (i < n)
	{
		if (n % i == 0)
			return 0;
		i++;
	}
	return 1;
}

int	main(int ac, char **av)
{
	int	n = 0;
	int i = 2;
	int sum = 0;


	if (ac == 2 && ft_atoi(av[1]) >= 0)
	{
		n = ft_atoi(av[1]);
		while (i <= n)
		{
			if (prime(i))
				sum += i;
			i++;
		}
		putnbr(sum);
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
}

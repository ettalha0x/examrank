#include<unistd.h>

int	ft_atoi(char *s)
{
	int res = 0;
	int sign = 1;

	while (*s <= 32)
		s++;
	if (*s == '-')
		sign = -1;
	while (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - 48);
		s++;
	}
	return (res * sign);
}

void	ft_putnbr(int n)
{
	if (n >= 0 && n <= 9)
	{
		n += 48;
		write(1, &n, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	main(int ac, char **av)
{
	int	i = 1;
	int	n;
	int	res;

	if(ac == 2)
	{
		n = ft_atoi(av[1]);
		while(i <= 9)
		{
			res = n * i;
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(n);
			write(1, " = ", 3);
			ft_putnbr(res);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}

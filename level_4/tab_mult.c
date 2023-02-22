#include<unistd.h>
#include<stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *s)
{
	int	res = 0;
	int sign = 1;

	while (*s && (*s == 32 || (*s >= 9 && *s <= 13)))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while ( *s && (*s >= '0' && *s <= '9'))
	{
		res = res * 10 + (*s - 48);
		s++;
	}
	return (res * sign);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar(n + 48);
}

int	main(int ac, char **av)
{
	int	i = 1;
	int	n = 0;
	if(ac == 2)
	{
		n = ft_atoi(av[1]);
		while(i <= 9)
		{
			ft_putnbr(i);
			ft_putchar(' ');
			ft_putchar('x');
			ft_putchar(' ');
			ft_putnbr(n);
			ft_putchar(' ');
			ft_putchar('=');
			ft_putchar(' ');
			ft_putnbr(n * i);
			ft_putchar('\n');
			i++;
		}
	}
	else
		write(1, "\n", 1);
}

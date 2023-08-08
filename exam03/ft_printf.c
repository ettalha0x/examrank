# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putnbr_hexa(unsigned long n)
{
	int		count;
	char	*base;
	count = 0;
	base = "0123456789abcdef";
	if (n >= 0 && n < 16)
		count += ft_putchar(base[n]);
	else if (n >= 16)
	{
		count += ft_putnbr_hexa(n / 16);
		count += ft_putnbr_hexa(n % 16);
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (s[i] == 'd')
				count += ft_putnbr(va_arg(args, int));
			else if (s[i] == 'x')
				count += ft_putnbr_hexa(va_arg(args, unsigned int));
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}

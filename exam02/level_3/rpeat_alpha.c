#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	is_valid(char c, int base)
{
	char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";
	while (base--)
	{
		if (digits[base] == c || digits2[base] == c)
		{
			return 1;
		}
	}
	return 0;
}

int	value_of(char c)
{
	if (c >= 0 && c <= 9)
		return (c - 48);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return 0;
}

int	ft_atoi_base(const char *str, int str_base)
{
	int res = 0;
	int sign;
	while (*str == 32 || (*str >=9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (is_valid(*str, str_base))
	{
		res = res * str_base + value_of(*str);
		str++;
	}
	return (res * sign);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("result: %d\n", ft_atoi_base(av[1], atoi(av[2])));
	return (0);
}

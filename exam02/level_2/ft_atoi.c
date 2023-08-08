#include<unistd.h>
// #include<stdio.h>


int	ft_atoi(const char *str)
{
	int	res;
	int	signe;

	res = 0;
	signe = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		signe = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ((*str >= '0' && *str <= '9'))
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * signe);
}

// int	main (int ac, char **av)
// {
// 	printf("%d\n", ft_atoi("+121214548"));
// }

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>


int	ft_nblen(int nb)
{
	int i = 0;
	int n = nb;
	if (nb == 0)
		return 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	if (nb < 0)
		return i + 1;
	return i;
}

char	*ft_itoa(int nb)
{
	int len = ft_nblen(nb);
	int i = 0;
	char *s = malloc(sizeof(char) * (len + 1));
	s[len--] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		s[0] = '-';
		i = 1;
	}
	while (len >= i)
	{
		s[len--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return s;
}

// int main(void)
// {
// 	int n = 256;
// 	char *s = ft_itoa(n);
// 	printf("size = %d\n", ft_nblen(n));
// 	printf("%s", &*s);
// }


#include<unistd.h>


int	valid(char c, int base)
{
	int i = 0;
	char *s1 = "0123456789ABCDEF";
	char *s2 = "0123456789abcdef";

	while (i < base)
	{
		if ( c == s1[i] || c == s2[i])
			return i;
		i++;
	}
	return -1;
}

int	ft_atoi_base(const char *s, int str_base)
{
	int i = 0;
	int res = 0;
	int sign = 1;
	while (s[i] <= 32)
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (valid(s[i], str_base) != -1)
	{
		res = res * str_base;
		res = res + valid(s[i], str_base);
		i++;
	}
	return res * sign;
}

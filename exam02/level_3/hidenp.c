#include<unistd.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return i;
}

int main(int ac, char **av)
{
	char *s1;
	char *s2;

	int i = 0;
	int j = 0;
	int c = 0;
	if (ac == 3)
	{
		s1 = av[1];
		s2 = av[2];
		while (s1[i])
		{
			//j = 0;
			while (s2[j])
			{
				if (s1[i] == s2[j])
				{
					c++;
					break ;
				}
				j++;
			}
			i++;
		}
		if (c == ft_strlen(s1))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
}

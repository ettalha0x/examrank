#include<unistd.h>

int main(int ac, char **av)
{
	char *s;
	int i = 0;
	if (ac == 2)
	{
		s = av[1];
		while (s[i])
		{
			if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
				s[i] = s[i] + 13;
			else if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
				s[i] = s[i] - 13;
			write(1, &s[i], 1);
			i++;
		}

	}
	write(1, "\n", 1);
}

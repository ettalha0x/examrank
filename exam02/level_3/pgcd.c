#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

void putnum(int n)
{
	if (n <= 9)
	{
		n += 48;
		write(1, &n, 1);
	}
	else
	{
		putnum(n / 10);
		putnum(n % 10);
	}
}

int main(int ac, char **av)
{
	int a = 0;
	int b = 0;
	int c = 0;
	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		while (a % b)
		{
			c = a % b;
			a = b;
			b = c;
		}
		putnum(b);
	}
	write(1, "\n", 1);
}

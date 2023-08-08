#include<unistd.h>
#include<stdio.h>
#include<string.h>

size_t	ft_strcspn(const char *s, const char *r)
{
	int i = 0;
	int j = 0;
	while (s[i])
	{
		j = 0;
		while (r[j])
		{
			if (s[i] != r[j])
				j++;
			else
				return i ;
		}
		i++;
	}
	return i;
}

// int main(void)
// {
// 	char *s = "ellho";
// 	char *r = "ahaa";

// 	printf("====> %lu\n", ft_strcspn(s, r));
// 	printf("====> %lu\n", strcspn(s, r));

// }

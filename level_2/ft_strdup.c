#include<unistd.h>
#include<stdlib.h>

char	*ft_strdup(char *src)
{
	int i = 0;
	while (src[i])
		i++;
	char *s = malloc(sizeof(char) * i + 1);
	if (!s)
		return NULL;
	i = 0;
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return s;
}

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *s, int *i)
{
	int j = 0;
	while (s[*i] && s[*i] != 32 && s[*i] != '\t' && s[*i] != '\n')
	{
		(*i)++;
		j++;
	}
	return j;
}

int	count_words(char *s)
{
	int	i = 0;
	int count = 0;
	while (s[i])
	{
		while (s[i] && s[i] <= 32)
			i++;
		if (s[i])
		{
			while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
				i++;
			count++;
		}
	}
	return count;
}

void	ft_copy(char **s1, char *s, int cw)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < cw)
	{
		while (s[k] && s[k] <= 32)
			k++;
		j = 0;
		while (s[k] != 32 && s[k] != '\t' && s[k] != '\n')
		{
			s1[i][j] = s[k];
			j++;
			k++;
		}
		s1[i][j] = 0;
		i++;
	}
	s1[i] = NULL;
}

char	**ft_split(char *s)
{
	char **s1;
	int i = 0;
	int j = 0;
	int cw = count_words(s);
	s1 = malloc(sizeof(char *) * (cw + 1));
	if (!s1)
		return 0;
	while (i < cw)
	{
		while ((s[j] && s[j] <= 32))
			j++;
		s1[i] = malloc(sizeof(char) * ft_strlen(s, &j) + 1);
		if (!s1[i])
			return 0;
		i++;
	}
	ft_copy(s1, s, cw);
	return s1;
}

int main(void)
{
	int i = 0;

	char **s1 = ft_split("   fghdfh      fgdfgh    dfgdfgh    \n   ");

	while (s1[i])
		printf("%s\n", s1[i++]);
}

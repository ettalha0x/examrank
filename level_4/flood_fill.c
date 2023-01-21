/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:54:38 by nettalha          #+#    #+#             */
/*   Updated: 2023/01/18 10:43:04 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

int	replace(char **s, int p, int i, int j)
{
	char	c;

	c = s[i][j];
	if (s[i - 1][j] && s[i - 1][j] == c)
	{
		s[i - 1][j] = 'F';
		p = 1;
	}
	if (s[i + 1][j] && s[i + 1][j] == c)
	{
		s[i + 1][j] = 'F';
		p = 1;
	}
	if (s[i][j - 1] && s[i][j - 1] == c)
	{
		s[i][j - 1] = 'F';
		p = 1;
	}
	if (s[i][j + 1] && s[i][j + 1] == c)
	{
		s[i][j + 1] = 'F';
		p = 1;
	}
	return (p);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	int	i;
	int	j;
	int	p;

	//p = 1;
	i = 0;
	j = 0;

	while (p == 1)
	{
		//p = 0;
		i = 0;
		while (i < size.y)
		{
			j = 0;
			while (j < size.x)
			{
				if (tab[i][j] == tab[begin.y][begin.x])
				{
					tab[i][j] = 'F';
					//p = replace(tab, p, i, j);
				}
				// else
				// 	write(1, &tab[i][j], 1);
				j++;
			}
			//write(1, "\n", 1);
			i++;
		}
	}
}

char**	make_area(char** zone, t_point size)
{
	char**	new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10001001",
		"10110001",
		"11100000",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	//printf("\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

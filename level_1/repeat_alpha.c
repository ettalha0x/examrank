/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:15:51 by nettalha          #+#    #+#             */
/*   Updated: 2023/01/03 20:38:36 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	get_index(char c)
{
	char	*arr;
	int		i;

	arr = "abcdefghjklmnopkrstuvwxyz";
	i = 0;
	while (arr[i])
	{
		if (arr[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void	repeat_alpha(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (j++ <= get_index(s[i]))
			write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	else
		write(1, "\n", 1);
}

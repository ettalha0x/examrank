/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:33:13 by nettalha          #+#    #+#             */
/*   Updated: 2023/01/03 22:15:04 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	search_and_replace(char *s, char a, char b)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			s[i] = b;
		i++;
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 4 && av[2][1] == '\0' && av[3][1] == '\0')
		search_and_replace(av[1], av[2][0], av[3][0]);
	else
		write(1, "\n", 1);
}

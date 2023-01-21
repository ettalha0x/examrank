/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:05:49 by nettalha          #+#    #+#             */
/*   Updated: 2023/01/03 16:05:52 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	first_word(char *s)
{
	while (*s && *s == ' ' && *s == '\t')
		s++;
	while (*s && *s != ' ' && *s != '\t')
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		first_word(av[1]);
	}
	else
		write(1, "\n", 1);
}

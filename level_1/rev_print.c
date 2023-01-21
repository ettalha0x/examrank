/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:40:28 by nettalha          #+#    #+#             */
/*   Updated: 2023/01/03 20:49:49 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rev_print(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	i--;
	while (i >= 0)
		write(1, &s[i--], 1);
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_print(av[1]);
	else
		write(1, "\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:13:16 by nettalha          #+#    #+#             */
/*   Updated: 2023/01/03 21:31:23 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	rotone(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'z' || s[i] == 'Z')
			s[i] -= 25;
		else if ((s[i] >= 'a' && s[i] < 'z') || (s[i] >= 'A' && s[i] < 'Z'))
			s[i] += 1;
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	else
		write(1, "\n", 1);
}

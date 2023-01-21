/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:52:28 by nettalha          #+#    #+#             */
/*   Updated: 2023/01/03 21:06:22 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	rot13(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'm')
			s[i] = s[i] + 13;
		else if (s[i] >= 'A' && s[i] <= 'M')
			s[i] = s[i] + 13;
		else if (s[i] >= 'n' && s[i] <= 'z')
			s[i] = s[i] - 13;
		else if (s[i] >= 'N' && s[i] <= 'Z')
			s[i] = s[i] - 13;
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rot13(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}

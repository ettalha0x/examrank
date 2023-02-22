/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:15:51 by nettalha          #+#    #+#             */
/*   Updated: 2023/02/07 10:18:08 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void print(char c, int n)
{
	while (n >= 0)
	{
		write(1, &c, 1);
		n--;
	}
}

int main(int ac, char **av)
{
	int i = 0;
	if(ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				print(av[1][i], av[1][i] = av[1][i] - 'A');
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
				print(av[1][i], av[1][i] = av[1][i] - 'a');
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}


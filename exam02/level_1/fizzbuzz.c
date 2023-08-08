/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:07:55 by nettalha          #+#    #+#             */
/*   Updated: 2023/01/03 16:32:28 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnum(int i)
{
	if (i > 9)
		ft_putnum(i / 10);
	write(1, &"0123456789"[i % 10], 1);
}

int	main(void)
{
	char	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0)
			write(1, "fizz\n", 5);
		else if (i % 5 == 0)
			write(1, "buzz\n", 5);
		else
		{
			ft_putnum(i);
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}

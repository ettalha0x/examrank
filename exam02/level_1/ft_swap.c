/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:02:36 by nettalha          #+#    #+#             */
/*   Updated: 2023/01/03 20:13:41 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_putnum(int i)
{
	if (i > 9)
		ft_putnum(i / 10);
	write(1, &"0123456789"[i % 10], 1);
}

int	main(void)
{
	int	*a;
	int	*b;
	int	x;
	int	y;

	x = 13;
	y = 37;
	a = &x;
	b = &y;
	ft_putnum(*a);
	ft_putnum(*b);
	ft_swap(a, b);
	ft_putnum(*a);
	ft_putnum(*b);
}

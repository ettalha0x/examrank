/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:47:32 by nettalha          #+#    #+#             */
/*   Updated: 2023/01/03 16:56:48 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnum(int i)
{
	if (i > 9)
		ft_putnum(i / 10);
	write(1, &"0123456789"[i % 10], 1);
}

int	main(void)
{
	int	i;

	i = ft_strlen("Hello");
	ft_putnum(i);
}

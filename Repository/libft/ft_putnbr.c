/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:05:37 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/10 14:12:32 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int	nb;
	int			div;

	if (n == 0)
		ft_putchar('0');
	else
	{
		nb = n;
		div = 1;
		while (nb /= 10)
			div *= 10;
		nb = n;
		if (n < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		while (div)
		{
			ft_putchar(((nb / div) % 10) + 48);
			div /= 10;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:28:56 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/10 14:12:45 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	int			div;

	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		nb = n;
		div = 1;
		while (nb /= 10)
			div *= 10;
		nb = n;
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			nb *= -1;
		}
		while (div)
		{
			ft_putchar_fd(((nb / div) % 10) + 48, fd);
			div /= 10;
		}
	}
}

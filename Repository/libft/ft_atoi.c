/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:48:31 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/16 11:33:41 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					nb;
	int					i;
	int					sign;
	unsigned long long	max;

	nb = 0;
	i = 0;
	sign = 1;
	max = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		max = max * 10 + str[i] - '0';
		if (max > 9223372036854775807)
			return ((sign == 1) ? -1 : 0);
		nb = nb * 10 + str[i++] - '0';
	}
	return (nb * sign);
}

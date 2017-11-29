/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:27:14 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/13 18:19:59 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_init_negative(int len, long *nb)
{
	char	*str;

	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	str[0] = '-';
	*nb *= -1;
	return (str);
}

char		*ft_itoa(int n)
{
	char		*str;
	long		nb;
	int			len;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	len = 1;
	while (nb /= 10)
		len++;
	nb = n;
	if (n < 0)
	{
		if ((str = ft_init_negative(++len, &nb)) == NULL)
			return (NULL);
	}
	else if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	while (len-- > 0 && nb)
	{
		str[len] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}

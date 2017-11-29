/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:08:53 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/15 11:32:44 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*s;
	char		*d;

	s = (const char*)src;
	d = (char*)dst;
	if (d != s)
	{
		if (d > s)
		{
			i = n;
			while (i-- > 0)
				d[i] = s[i];
		}
		else
		{
			i = 0;
			while (i < n)
			{
				d[i] = s[i];
				i++;
			}
		}
	}
	return (dst);
}

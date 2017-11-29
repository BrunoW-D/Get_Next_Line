/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:08:00 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/15 11:32:32 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*s;
	char		*d;

	s = (const char*)src;
	d = (char*)dst;
	while (n > 0)
	{
		*d++ = *s;
		if (*s++ == (char)c)
			return (d);
		n--;
	}
	return (NULL);
}

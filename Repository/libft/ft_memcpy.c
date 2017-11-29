/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:20:01 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/15 11:40:01 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = (const char*)src;
	d = (char*)dst;
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dst);
}

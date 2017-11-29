/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:06:57 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/15 11:22:33 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*s;

	s = (unsigned char*)str;
	while (len > 0)
	{
		*s++ = c;
		len--;
	}
	return (str);
}

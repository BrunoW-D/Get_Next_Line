/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:23:53 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/13 17:39:28 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;

	if (s1 && s2)
	{
		i = 0;
		dst = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2));
		if (!dst)
			return (NULL);
		while (*s1)
		{
			dst[i] = *s1;
			i++;
			s1++;
		}
		while (*s2)
		{
			dst[i] = *s2;
			i++;
			s2++;
		}
		return (dst);
	}
	else
		return (NULL);
}

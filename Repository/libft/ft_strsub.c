/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:23:12 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/15 11:56:56 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (s)
	{
		i = 0;
		if ((dst = ft_strnew(len)) == NULL)
			return (NULL);
		while (i < len)
		{
			dst[i] = s[start + i];
			i++;
		}
		return (dst);
	}
	else
		return (NULL);
}

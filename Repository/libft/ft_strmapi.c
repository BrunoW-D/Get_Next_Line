/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:22:11 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/15 11:55:06 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	int		i;

	if (s && f)
	{
		i = 0;
		if ((dst = ft_strdup((char*)s)) == NULL)
			return (NULL);
		while (s[i])
		{
			dst[i] = (*f)(i, s[i]);
			i++;
		}
		return (dst);
	}
	else
		return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:21:31 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/15 11:54:44 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			dst[i] = (*f)(s[i]);
			i++;
		}
		return (dst);
	}
	else
		return (NULL);
}

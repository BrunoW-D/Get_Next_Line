/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:35:39 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/13 16:46:16 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen((char*)s);
	if (!c)
		return ((char*)s + i);
	while (s[i] != c && i >= 0)
		i--;
	if (i >= 0)
		return ((char*)s + i);
	return (NULL);
}

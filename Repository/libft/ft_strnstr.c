/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:42:27 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/10 16:37:40 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*to_find)
		return ((char*)str);
	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == *to_find)
		{
			j = 0;
			while (str[i + j] && to_find[j] && str[i + j] == to_find[j]
					&& i + j < len)
				j++;
			if (!to_find[j])
				return ((char*)str + i);
		}
		i++;
	}
	return (NULL);
}

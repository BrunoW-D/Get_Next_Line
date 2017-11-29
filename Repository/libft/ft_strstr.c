/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:44:50 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/16 11:59:45 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char	*ptr1;
	char	*ptr2;
	char	*s;

	s = (char*)str;
	if (!*to_find)
		return (s);
	while (*s)
	{
		if (*s == *to_find)
		{
			ptr1 = s;
			ptr2 = (char*)to_find;
			while (*ptr1 && *ptr2 && *ptr1 == *ptr2)
			{
				ptr1++;
				ptr2++;
			}
			if (!*ptr2)
				return (s);
		}
		s++;
	}
	return (NULL);
}

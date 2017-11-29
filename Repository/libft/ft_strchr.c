/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:30:07 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/10 14:52:02 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	ch = (char)c;
	i = 0;
	while (s[i])
	{
		if (ch == s[i])
			return ((char*)s + i);
		i++;
	}
	if (ch == '\0')
		return ((char*)s + i);
	else
		return (NULL);
}

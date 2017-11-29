/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:40:39 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/10 10:18:21 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	i = size;
	while (i >= 0)
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

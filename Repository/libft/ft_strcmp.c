/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:45:51 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/16 11:32:21 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if (*str1 && *str2 && *str1 == *str2)
		return (ft_strcmp(s1 + 1, s2 + 1));
	return (*str1 - *str2);
}

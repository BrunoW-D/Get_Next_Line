/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:46:59 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/16 11:32:44 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	if (*str1 && *str2 && *str1 == *str2 && n > 0)
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
	return (*str1 - *str2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:57:50 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/13 17:33:07 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	while (i > 0)
	{
		i--;
		s[i] = '\0';
	}
}

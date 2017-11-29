/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:35:14 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/13 17:46:14 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dst;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = i;
	while (s[j])
		j++;
	j--;
	while (j > i && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	if ((dst = ft_strnew(j - i + 1)) == NULL)
		return (NULL);
	k = 0;
	while (i + k <= j)
	{
		dst[k] = s[i + k];
		k++;
	}
	return (dst);
}

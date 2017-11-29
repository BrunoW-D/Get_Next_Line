/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:24:42 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/16 12:24:32 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_alloc_words(char const *str, char **string, char s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = -1;
	while (str[i])
	{
		k = 0;
		if (str[i] == s)
			i++;
		else
		{
			j++;
			while (str[i] != s && str[i])
			{
				i++;
				k++;
			}
			if ((string[j] = (char*)malloc(sizeof(char) * (k + 1))) == NULL)
				return (NULL);
			string[j][k] = '\0';
		}
	}
	return (string);
}

static char	**ft_alloc_tab(char const *str, char s)
{
	int		i;
	int		nb_words;
	char	**string;

	i = 0;
	nb_words = 0;
	while (str[i])
	{
		if (str[i] == s)
			i++;
		else
		{
			nb_words++;
			while (str[i] != s && str[i])
				i++;
		}
	}
	string = (char**)malloc(sizeof(char*) * (nb_words + 1));
	if (string == NULL)
		return (NULL);
	string[nb_words] = NULL;
	return (ft_alloc_words(str, string, s));
}

char		**ft_strsplit(char const *str, char s)
{
	char	**string;
	int		i;
	int		j;
	int		k;

	if (!s || !str)
		return (NULL);
	if ((string = ft_alloc_tab(str, s)) == NULL)
		return (NULL);
	i = 0;
	j = -1;
	while (str[i])
	{
		k = 0;
		if (str[i] == s)
			i++;
		else
		{
			j++;
			while (str[i] != s && str[i])
				string[j][k++] = str[i++];
		}
	}
	return (string);
}

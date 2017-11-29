/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:40:51 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/29 15:59:27 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc_str(char *str, int *len, int *i)
{
	char	*str_tmp;

	str_tmp = NULL;
	if (str)
	{
		str_tmp = ft_strdup(str);
		*i = ft_strlen(str);
		*len += *i;
	}
	if ((str = ft_strnew(*len)) == NULL)
		return (NULL);
	if (str_tmp)
	{
		str = ft_strcpy(str, str_tmp);
		free(str_tmp);
	}
	str[*len - 1] = '\0';
	return (str);
}

int		end_line(char **str, char **line)
{
	int	i;

	i = 0;
	if (!str[0][0])
	{
		*line = NULL;
		free(*str);
		return (0);
	}
	while (str[0][i])
	{
		if (str[0][i] == '\n')
		{
			str[0][i] = '\0';
			*line = ft_strdup(*str);
			*str = *str + i + 1;
			return (1);
		}
		i++;
	}
	*line = ft_strdup(*str);
	return (2);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	int			ret;
	int			len;
	int			i;
	int			end;

	len = BUFF_SIZE;
	i = 0;
	end = 0;
	if (fd < 0 || fd == 1 || fd == 2)
		return (-1);
	if ((str = alloc_str(str, &len, &i)) == NULL)
		return (-1);
	while ((ret = read(fd, str + i, BUFF_SIZE)))
	{
		if ((end = end_line(&str, line)) == 1)
			return (1);
		else if (end == 2 && ((str = alloc_str(str, &len, &i)) == NULL))
			return (-1);
	}
	if (!(end = end_line(&str, line)))
		return (0);
	else if (end == 2)
		str[0] = '\0';
	return (1);
}

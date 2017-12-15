/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:40:51 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/15 13:37:08 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc_str(char *str, int *len, int *i)
{
	char	*str_tmp;

	str_tmp = NULL;
	if (str != NULL)
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

t_gnl	*add_gnl(t_gnl **first_gnl, int fd, int *len, int *i)
{
	t_gnl	*new_gnl;
	t_gnl	*previous;

	new_gnl = *first_gnl;
	while (new_gnl)
	{
		if (new_gnl->fd == fd)
		{
			if (!(new_gnl->str = alloc_str(new_gnl->str, len, i)))
				return (NULL);
			return (new_gnl);
		}
		previous = new_gnl;
		new_gnl = new_gnl->next;
	}
	if (!((new_gnl = (t_gnl*)malloc(sizeof(t_gnl)))
			&& (new_gnl->str = alloc_str(NULL, len, i))))
		return (NULL);
	new_gnl->fd = fd;
	new_gnl->next = NULL;
	if (!*first_gnl)
		*first_gnl = new_gnl;
	else if (previous)
		previous->next = new_gnl;
	return (new_gnl);
}

void	set_free(t_gnl **gnlptr)
{
	t_gnl	*gnl;

	gnl = *gnlptr;
	*gnlptr = gnl->next;
	free(gnl->str);
	gnl->str = NULL;
	gnl->fd = -1;
	//free(gnl);
	//gnl = NULL;
}

int		end_line(t_gnl **gnlptr, char **line, int ret)
{
	int		i;
	char	*str;

	i = 0;
	str = (*gnlptr)->str;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			*line = ft_strdup(str);
			(*gnlptr)->str = str + i + 1;
			return (1);
		}
		i++;
	}
	if (ret == 0 && i == 0)
		return (0);
	*line = ft_strdup(str);
	return (2);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*first_gnl = NULL;
	int				len;
	int				i;
	int				ret;
	t_gnl			*gnl;

	len = BUFF_SIZE;
	i = 0;
	ret = 0;
	if (fd < 0 || (gnl = add_gnl(&first_gnl, fd, &len, &i)) == NULL)
		return (-1);
	while ((ret = read(fd, gnl->str + i, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		if ((ret = end_line(&gnl, line, ret)) == 1)
			return (1);
		if (ret == 2 && ((gnl->str = alloc_str(gnl->str, &len, &i)) == NULL))
			return (-1);
	}
	if ((ret = end_line(&gnl, line, ret)) == 2)
		gnl->str = NULL;
	else if (ret == 0)
		set_free(&gnl);
	return (ret ? 1 : 0);
}

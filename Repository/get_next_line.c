/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:40:51 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/15 18:39:27 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc_str(char *str, t_data *data)
{
	char	*str_tmp;

	str_tmp = NULL;
	if (str != NULL)
	{
		str_tmp = ft_strdup(str);
		data->i = ft_strlen(str);
		data->len += data->i;
	}
	if ((str = ft_strnew(data->len)) == NULL)
		return (NULL);
	if (str_tmp)
	{
		str = ft_strcpy(str, str_tmp);
		free(str_tmp);
	}
	str[data->len - 1] = '\0';
	return (str);
}

t_gnl	*add_gnl(t_gnl **first_gnl, int fd, t_data *data)
{
	t_gnl	*new_gnl;
	t_gnl	*previous;

	new_gnl = *first_gnl;
	while (new_gnl)
	{
		if (new_gnl->fd == fd)
		{
			if (!(new_gnl->str = alloc_str(new_gnl->str, data)))
				return (NULL);
			return (new_gnl);
		}
		previous = new_gnl;
		new_gnl = new_gnl->next;
	}
	if (!((new_gnl = (t_gnl*)malloc(sizeof(t_gnl)))
			&& (new_gnl->str = alloc_str(NULL, data))))
		return (NULL);
	new_gnl->fd = fd;
	new_gnl->next = NULL;
	if (!*first_gnl)
		*first_gnl = new_gnl;
	else if (previous)
		previous->next = new_gnl;
	return (new_gnl);
}

void	set_free(t_gnl **first_gnl, int fd)
{
	t_gnl	*gnl;
	t_gnl	*previous;

	gnl = *first_gnl;
	previous = *first_gnl;
	while (gnl)
	{
		if (gnl->fd == fd)
		{
			free(gnl->str);
			gnl->str = NULL;
			previous->next = gnl->next;
			gnl->next = NULL;
			free(gnl);
			gnl = NULL;
			return ;
		}
		previous = gnl;
		gnl = gnl->next;
	}
}

int		end_line(t_gnl **gnlptr, char **line, t_data *data)
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
	if (data->ret == 0 && i == 0)
		return (0);
	*line = ft_strdup(str);
	return (2);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*first_gnl = NULL;
	t_gnl			*gnl;
	t_data			*data;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		return (-1);
	data->len = BUFF_SIZE;
	if (fd < 0 || (gnl = add_gnl(&first_gnl, fd, data)) == NULL)
		return (-1);
	while ((data->ret = read(fd, gnl->str + data->i, BUFF_SIZE)))
	{
		if (data->ret == -1)
			return (-1);
		if ((data->end = end_line(&gnl, line, data)) == 1)
			return (1);
		if (data->end == 2
				&& ((gnl->str = alloc_str(gnl->str, data)) == NULL))
			return (-1);
	}
	if ((data->end = end_line(&gnl, line, data)) == 2)
		gnl->str = NULL;
	else if (data->end == 0)
		set_free(&first_gnl, fd);
	return (data->end ? 1 : 0);
}

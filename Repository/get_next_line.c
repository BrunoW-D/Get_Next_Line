/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:40:51 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/22 19:08:17 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		alloc_str(t_gnl **gnlptr, int re)
{
	char	*str_tmp;

	str_tmp = NULL;
	if (re == 1)
	{
		if ((str_tmp = ft_strdup((*gnlptr)->str)) == NULL)
			return (0);
		free((*gnlptr)->str);
		(*gnlptr)->str = NULL;
		(*gnlptr)->i = ft_strlen(str_tmp);
		(*gnlptr)->len += (*gnlptr)->i;
	}
	if (((*gnlptr)->str = ft_strnew((*gnlptr)->len)) == NULL)
		return (0);
	if (str_tmp)
	{
		ft_strcpy((*gnlptr)->str, str_tmp);
		free(str_tmp);
		str_tmp = NULL;
	}
	(*gnlptr)->str[(*gnlptr)->len - 1] = '\0';
	return (1);
}

t_gnl	*add_gnl(t_gnl **first_gnl, int fd)
{
	t_gnl	*gnl;
	t_gnl	*new_gnl;

	gnl = *first_gnl;
	while (gnl && gnl->next && gnl->fd != fd)
		gnl = gnl->next;
	if (gnl && gnl->fd == fd)
	{
		if (!(alloc_str(&gnl, 1)))
			return (NULL);
		return (gnl);
	}
	if ((new_gnl = (t_gnl*)malloc(sizeof(t_gnl))) == NULL)
		return (NULL);
	new_gnl->fd = fd;
	new_gnl->len = BUFF_SIZE;
	if (!(alloc_str(&new_gnl, 0)))
		return (NULL);
	new_gnl->next = NULL;
	if (gnl && !gnl->next)
		return ((gnl->next = new_gnl));
	return ((*first_gnl = new_gnl));
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

int		check_nl(t_gnl **gnlptr, char **line, int ret)
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
			//free((*gnlptr)->str);
			//(*gnlptr)->str = NULL;
			//ft_strdup(str + i + 1);
			ft_strncpy((*gnlptr)->str, str + i + 1, ft_strlen(str + i + 1));
			return (1);
		}
		i++;
	}
	if (ret == 0 && str[0] == '\0')
		return (0);
	else if (ret == 0)
		*line = ft_strdup(str);
	return (2);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*first_gnl;
	t_gnl			*gnl;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE < 1
			|| (gnl = add_gnl(&first_gnl, fd)) == NULL)
		return (-1);
	while ((ret = read(fd, gnl->str + gnl->i, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		if ((ret = check_nl(&gnl, line, ret)) == 1)
			return (1);
		if (ret == 2 && (!(alloc_str(&gnl, 1))))
			return (-1);
	}
	if ((ret = check_nl(&gnl, line, ret)) == 2)
		gnl->str[0] = '\0';
	else if (ret == 0)
		set_free(&first_gnl, fd);
	return (ret ? 1 : 0);
}

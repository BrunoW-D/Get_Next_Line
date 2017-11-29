/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:40:51 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/29 17:21:34 by bwang-do         ###   ########.fr       */
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

t_gnl	*add_gnl(t_gnl *gnl, int fd, int len, int i)
{
	t_gnl	*new_gnl;
	int		found;

	found = 0;
	new_gnl = gnl;
	while (new_gnl->next)
	{
		if (new_gnl->fd == fd)
		{
			if ((new_gnl->str = alloc_str(new_gnl->str, &len, &i)) == NULL)
				return (NULL);
			found = 1;
		}
		new_gnl = new_gnl->next;
	}
	if (!found)
	{
		if ((new_gnl = (t_gnl*)malloc(sizeof(t_gnl))) == NULL)
			return (NULL);
		new_gnl->fd = fd;
		if ((new_gnl->str = alloc_str(new_gnl->str, &len, &i)) == NULL)
			return (NULL);
		new_gnl->next = NULL;
		if (!gnl)
			gnl = new_gnl;
	}
	return (new_gnl);
}

void	free_gnl(t_gnl **first_gnl)
{
	t_gnl	*gnl;

	gnl = *first_gnl;
	while (gnl->next)
	{
		free(gnl->str);
		free(gnl);
		gnl = gnl->next;
	}
	if (gnl)
	{
		free(gnl->str);
		free(gnl);
		*first_gnl = NULL;
	}
}

int		end_line(char *str, char **line)
{
	int	i;

	i = 0;
	if (!str[0])
	{
		*line = NULL;
		return (0);
	}
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			*line = ft_strdup(str);
			str = str + i + 1;
			return (1);
		}
		i++;
	}
	*line = ft_strdup(str);
	return (2);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*first_gnl = NULL;
	int				ret;
	int				len;
	int				i;
	int				end;
	t_gnl			*gnl;

	len = BUFF_SIZE;
	i = 0;
	end = 0;
	if (fd < 0 || fd == 1 || fd == 2)
		return (-1);
	if ((gnl = add_gnl(first_gnl, fd, len, i)) == NULL)
		return (-1);
	while ((ret = read(fd, gnl->str + i, BUFF_SIZE)))
	{
		if ((end = end_line(gnl->str, line)) == 1)
			return (1);
		else if (end == 2
				&& ((gnl->str = alloc_str(gnl->str, &len, &i)) == NULL))
			return (-1);
	}
	if (!(end = end_line(gnl->str, line)))
		return (0);
	else if (end == 2)
		gnl->str[0] = '\0';
	return (1);
}

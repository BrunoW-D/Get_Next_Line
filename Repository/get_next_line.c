/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:40:51 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/02 16:59:46 by bwang-do         ###   ########.fr       */
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

t_gnl	*make_gnl(t_gnl **first_gnl, int fd, int *len, int *i)
{
	t_gnl	*new_gnl;

	if (!((new_gnl = (t_gnl*)malloc(sizeof(t_gnl)))
				&& (new_gnl->str = alloc_str(NULL, len, i))))
		return (NULL);
	new_gnl->fd = fd;
	new_gnl->next = NULL;
	if (*first_gnl)
		first_gnl[0]->next = new_gnl;
	else
		*first_gnl = new_gnl;
	return (new_gnl);
}

t_gnl	*add_gnl(t_gnl **first_gnl, int fd, int *len, int *i)
{
	t_gnl	*new_gnl;

	new_gnl = *first_gnl;
	if (*first_gnl)
	{
		if (new_gnl->fd == fd)
		{
			if (!(new_gnl->str = alloc_str(new_gnl->str, len, i)))
				return (NULL);
			return (new_gnl);
		}
		while (new_gnl->next)
		{
			new_gnl = new_gnl->next;
			if (new_gnl->fd == fd)
			{
				if (!(new_gnl->str = alloc_str(new_gnl->str, len, i)))
					return (NULL);
				return (new_gnl);
			}
		}
		new_gnl = new_gnl->next;
	}
	return ((new_gnl = make_gnl(first_gnl, fd, len, i)));
}

int		end_line(t_gnl **gnlptr, char **line)
{
	int		i;
	char	*str;
	t_gnl	*gnl;

	i = 0;
	gnl = *gnlptr;
	str = gnl->str;
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
			gnl->str = str + i + 1;
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
		if ((ret = end_line(&gnl, line)) == 1)
			return (1);
		else if (ret == 2
				&& ((gnl->str = alloc_str(gnl->str, &len, &i)) == NULL))
			return (-1);
	}
	ret = end_line(&gnl, line);
	if (ret == 2)
		gnl->str[0] = '\0';
	return (ret ? 1 : 0);
}

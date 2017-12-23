/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 12:15:48 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/23 19:00:31 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*new_gnl(int fd)
{
	t_gnl	*gnl;

	if ((gnl = (t_gnl*)malloc(sizeof(t_gnl))) == NULL)
		return (NULL);
	gnl->fd = fd;
	ft_bzero(gnl->buff, BUFF_SIZE + 1);
	gnl->next = NULL;
	return (gnl);
}

t_gnl	*get_gnl(t_gnl **first_gnl, int fd)
{
	t_gnl	*gnl;

	gnl = *first_gnl;
	while (gnl && gnl->next && gnl->fd != fd)
		gnl = gnl->next;
	if (gnl && gnl->fd == fd)
		return (gnl);
	if (gnl && !gnl->next)
		return ((gnl->next = new_gnl(fd)));
	return ((*first_gnl = new_gnl(fd)));
}

char	*ft_re_strnjoin(char *s1, char const *s2, size_t n)
{
	char	*str_tmp;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	if ((str_tmp = ft_strdup(s1)) == NULL)
		return (NULL);
	free(s1);
	s1 = NULL;
	if ((s1 = ft_strnew(ft_strlen(str_tmp) + n)) == NULL)
		return (NULL);
	ft_strcpy(s1, str_tmp);
	free(str_tmp);
	str_tmp = NULL;
	ft_strncat(s1, s2, n);
	return (s1);
}

int		check_nl(t_gnl *gnl, char **line, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (gnl->buff[i] == '\n')
		{
			if ((*line = ft_re_strnjoin(*line, gnl->buff, i)) == NULL)
				return (-1);
			ft_strncpy(gnl->buff, gnl->buff + i + 1, len - i);
			return (1);
		}
		i++;
	}
	if ((*line = ft_re_strnjoin(*line, gnl->buff, BUFF_SIZE)) == NULL)
		return (-1);
	ft_bzero(gnl->buff, BUFF_SIZE);
	return (2);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*first_gnl;
	t_gnl			*gnl;
	int				ret;
	int				nl;

	if (fd < 0 || !line || BUFF_SIZE < 1 || !(gnl = get_gnl(&first_gnl, fd)))
		return (-1);
	if ((*line = ft_strnew(1)) == NULL)
		return (-1);
	if (gnl->buff[0] && (nl = check_nl(gnl, line, ft_strlen(gnl->buff))) != 2)
		return (nl);
	while ((ret = read(fd, gnl->buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		if ((nl = check_nl(gnl, line, ret)) != 2)
			return (nl);
	}
	return (**line ? 1 : 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:25:17 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/29 17:00:27 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_gnl
{
	int				fd;
	char			*str;
	struct s_gnl	*next;
}					t_gnl;

int		get_next_line(const int fd, char **line);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strnew(size_t size);
#endif

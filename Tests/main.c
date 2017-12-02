/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:53:07 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/02 12:55:39 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Repository/get_next_line.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd;
	int		fd2;
	int		i;
	char	**line;

	line = (char**)malloc(sizeof(char*) * 2);
	line[1] = NULL;
	i = 0;
	fd = open("../Tests/test3", O_RDONLY);
	fd2 = open("../Tests/test4", O_RDONLY);
	if (fd == -1)
		return (0);
	while (i < 6)
	{
		//get_next_line(fd, line);
		printf("fd  - %d : %s\n", get_next_line(fd, line), *line);
		//puts(*line);
		printf("fd2 - %d : %s\n", get_next_line(fd2, line), *line);
		i++;
	}
	get_next_line(fd, line);
	puts(*line);
	get_next_line(fd2, line);
	puts(*line);
	close(fd2);
	if (close(fd) == -1)
		return (0);
	return (0);
}

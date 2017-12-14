/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:53:07 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/14 16:37:45 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Repository/get_next_line.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		i;
	char	**line;

	line = (char**)malloc(sizeof(char*) * 2);
	line[1] = NULL;
	i = 0;
	fd1 = open("../Tests/test", O_RDONLY);
	fd2 = open("../Tests/test2", O_RDONLY);
	fd3 = open("../Tests/test3", O_RDONLY);
	fd4 = open("../Tests/test4", O_RDONLY);
	if (fd1 == -1)
		return (0);
	while (i < 5)
	{
		//get_next_line(fd, line);
		printf("fd1 - %d : %s\n", get_next_line(fd1, line), *line);
		//puts(*line);
		printf("fd2 - %d : %s\n", get_next_line(fd2, line), *line);
		printf("fd3 - %d : %s\n", get_next_line(fd3, line), *line);
		printf("fd4 - %d : %s\n", get_next_line(fd4, line), *line);
		i++;
	}
	/*
	get_next_line(fd1, line);
	puts(*line);
	get_next_line(fd2, line);
	puts(*line);
	get_next_line(fd3, line);
	puts(*line);
	get_next_line(fd4, line);
	puts(*line);
	*/
	close(fd2);
	close(fd3);
	close(fd4);
	if (close(fd1) == -1)
		return (0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:53:07 by bwang-do          #+#    #+#             */
/*   Updated: 2017/11/29 13:51:28 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Repository/get_next_line.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd;
	int		i;
	char	**line;

	line = (char**)malloc(sizeof(char*) * 2);
	line[1] = NULL;
	i = 0;
	fd = open("../Tests/test3", O_RDONLY);
	//fd = 0;
	if (fd == -1)
		return (0);
	while (i < 10)
	{
		//get_next_line(fd, line);
		printf("%d : %s\n", get_next_line(fd, line), *line);
		puts(*line);
		i++;
	}
	get_next_line(fd, line);
	puts(*line);
	if (close(fd) == -1)
		return (0);
	return (0);
}

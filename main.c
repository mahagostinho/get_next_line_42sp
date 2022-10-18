/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:39:27 by marcarva          #+#    #+#             */
/*   Updated: 2022/10/14 20:41:51 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("coming_back_to_life", O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	free(line);
	fd = close(fd);
	return (0);
}

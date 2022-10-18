/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:07:44 by marcarva          #+#    #+#             */
/*   Updated: 2022/10/18 20:42:16 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("teste", O_RDONLY);
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

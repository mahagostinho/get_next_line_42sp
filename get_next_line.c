/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:07:11 by marcarva          #+#    #+#             */
/*   Updated: 2022/10/18 17:21:00 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
		save = ft_calloc(1, 1);
	save = read_and_save(fd, save);
	if (!ft_strlen(save))
	{
		free(save);
		return (NULL);
	}
	else
	{
		line = get_line(save);
		save = update_save(save);
	}
	return (line);
}

char	*read_and_save(int fd, char *join_save)
{
	char	*buffer;
	ssize_t	reader;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!find_new_line(join_save))
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader <= 0)
		{
			free(buffer);
			return (join_save);
		}
		buffer[reader] = '\0';
		join_save = ft_strjoin(join_save, buffer);
		if (!join_save)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (join_save);
}

char	*get_line(char *old_save)
{
	char	*line;
	int		i;

	i = 0;
	if (!old_save)
		return (NULL);
	while (old_save[i] && old_save[i] != '\n')
		i++;
	if (old_save[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (old_save[i] && old_save[i] != '\n')
	{
		line[i] = old_save[i];
		i++;
	}
	if (old_save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_save(char *old_save)
{
	char	*updated;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!old_save)
		return (NULL);
	while (old_save[i] && old_save[i] != '\n')
		i++;
	if (old_save[i] == '\n')
		i++;
	updated = malloc(ft_strlen(old_save) - i + 1);
	if (!updated)
		return (NULL);
	while (old_save[i])
		updated[j++] = old_save[i++];
	updated[j] = '\0';
	free(old_save);
	return (updated);
}

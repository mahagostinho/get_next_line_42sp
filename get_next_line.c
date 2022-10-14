#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	else
	{
		line = get_line(save);
		save = update_save(save);
	}
	return (line);
}

char *read_and_save(int fd, char *save)
{
	char *buffer;
	ssize_t bytes_read;

	bytes_read = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(save, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_line(char *save)
{
	int 	i;
	char	*line;

	i = 0;
	if (!save)
	{
		free(save);
		return (NULL);
	}
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] && save[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line [i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i] = '\n';
	line[++i] = '\0';
	return (line);
}

char	*update_save(char *save)
{
	size_t 	i;
	int		j;
	char	*save_update;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] && save[i] == '\n')
		i++;
	save_update = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!save_update)
		return (NULL);
	while (save[i])
		save_update[j++] = save[i++];
	save_update[j] = '\0';
	free(save);
	return (save_update);
}
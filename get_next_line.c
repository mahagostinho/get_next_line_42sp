#define BUFFER_SIZE 5
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char *line;

	printf("Abrindo o arquivo para leitura ...\n");
	fd = open("teste", O_RDONLY);
	// para garantir que o arquivo foi aberto corretamente:
	if (fd < 0)
	{
		printf("Erro ao abrir o arquivo\n");
		return (-1);
	}
	printf("Arquivo aberto!\n");
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		/*estamos omitindo todos os \n nesse printf, pois a função get_next_line
		deve incluir um \n no final de cada linha */
		printf("%s", line);
	}
	close(fd);
	return (0);
}

char *get_next_line(int fd)
{
	static char *save;
	char 		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
		save = ft_strdup("");
	line = NULL;
	save = ft_read_and_keep(fd, save); // ler até encontrar um \n
	if (!save)
		return (NULL);
	line = ft_get_line(save);  // salvar a linha até o \n
	save = ft_save_rest(save); // atualizar o ponteiro save com os caracteres após o \n
	return (line);
}

char *ft_read_and_keep(int fd, char *save)
{
	size_t	bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read && !ft_strchr(save, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || bytes_read == 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	printf("%ld\n", ft_strlen(save));
	return (save);
}

char    *ft_get_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char    *ft_save_rest(char *save)
{
	char	*rest;
	int		i;
	int		j;
	
	i = 0;
	while(save && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(save)- i + 1));
	if (!rest)
		return (NULL);
	j =0;
	while (save[i])
		rest[j++] = save[i++];
	rest[j] = '\0';
	free(save);
	return (rest);
}

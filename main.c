#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("teste", O_RDONLY);
	//inicializar a variável para poder usá-la no loop abaixo
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		/*estamos omitindo todos os \n nesse printf, pois a função get_next_line
		deve incluir um \n no final de cada linha */
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}

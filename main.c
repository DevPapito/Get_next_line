#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("code.txt", O_RDONLY);
	//char	*line = get_next_line(fd);
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	//printf("%s", line);
	//free(line);
	return (0);
}

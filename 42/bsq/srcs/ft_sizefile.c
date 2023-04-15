#include "ft_app.h"

int	ft_size_file(char *filename)
{
	int size;
	char buf;
	int fd;

	size = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, &buf, 1) && fd != -1)
		size++;
	close(fd);
	return (size);
}
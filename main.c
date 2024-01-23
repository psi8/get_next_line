#include "get_next_line.h"
#include "fcntl.h"
#include "stdio.h"

char	*get_next_line(int fd);

int	main()
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("test2.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error\n");
		return (1);
	}
	next_line = get_next_line(fd);
	printf("%s", next_line);	
	while (next_line)
		{
			next_line = get_next_line(fd);
			if (next_line)
				printf("%s", next_line);
		}
	if (close(fd) == -1)
	{
		printf("close() error\n");
		return (1);
	}

	return (0);
}

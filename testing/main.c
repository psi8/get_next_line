int main()
{
	int fd;
	fd = open("testing/test", O_RDONLY);
	if(fd == -1)
	{
		printf("open() error\n");
		return(1);
	}
	get_next_line(fd);
	if(close(fd) == -1)
	{
		printf("close() error\n");
		return (1);
	}
	return (0);
}
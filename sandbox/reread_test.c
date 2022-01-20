#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

#include "../includes/so_long.h"
#include "../lib/gnl/get_next_line.h"

// 一度closeしたファイルはもう一度最初から読み込まれる

int	main()
{
	int	status;

	int fd = open("files/one_line", O_RDONLY);
	char *line = get_next_line(fd, &status);
	printf("line : %s\n", line);
	line = get_next_line(fd, &status);
	printf("line : %s\n", line);
	close(fd);
	fd = open("files/one_line", O_RDONLY);
	line = get_next_line(fd, &status);
	printf("line : %s\n", line);
	
	return (0);
}
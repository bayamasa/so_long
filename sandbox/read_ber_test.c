#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

#include "../lib/gnl/get_next_line.h"

int	main()
{
	int fd = open("files/line", O_RDONLY);
	printf("fd = %d\n", fd);
	char *str1 = get_next_line(fd);
	printf("str1 : %s\n", str1);
	return (0);
}

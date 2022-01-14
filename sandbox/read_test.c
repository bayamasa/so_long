#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

#include "../lib/gnl/get_next_line.h"
#include "../so_long.h"

size_t	count_line_num(char *filepath)
{
	size_t	i;
	char	*line;
	int		status;
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		abort_so_long(NULL, NULL);
	// do-while文を使いたいが、ないので最初の一回は外側でカウントする
	i = 0;
	status = true;
	line = get_next_line(fd, &status);
	if (status == false)
		abort_so_long(line, NULL);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd, &status);
		if (status == false)
			abort_so_long(line, NULL);
		i++;
	}
	close(fd);
	return (i);
}

char	**store_map_from_file(char *filepath)
{
	int		fd;
	char	*line;
	char	**map;


	
}


int	main()
{
	char **map;
	char *filepath = "files/one_line";

	// printf("count_line_num(filepath) = %zu\n", count_line_num(filepath));
	return (0);
}

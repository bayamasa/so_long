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

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		printf("one_line : %s\n", map[i]);
		// while (map[i][j] != '\n' && map[i][j] != '\0')
		// {
		// 	printf("map[i][j] = %c\n", map[i][j]);
		// 	j++;
		// }
		i++;
	}
}

char	**store_all_line(char *filepath, char **map)
{
	int		fd;
	char	*line;
	int		status;
	int		h;

	h = 0;
	status = true;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		abort_so_long(NULL, map);
	while (true)
	{
		line = get_next_line(fd, &status);
		if (status == false)
			abort_so_long(line, map);
		if (line == NULL)
		{
			// NULL止めしないと"a.out"の文字列が出てしまう。なぜ
			map[h] = NULL;
			break ;
		}
		printf("line : %s\n", line);
		map[h] = line;
		h++;
	}
	print_map(map);
	return (map);
}


char	**store_map_from_file(char *filepath)
{
	int		fd;
	char	*line;
	char	**map;
	size_t	line_num;

	line_num = count_line_num(filepath);
	map = (char **)malloc(sizeof(char *) * line_num);

}


int	main()
{
	char **map;
	char *filepath = "files/one_line";

	store_all_line(filepath, map);
	return (0);
}

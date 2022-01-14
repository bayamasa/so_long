#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

#include "../lib/gnl/get_next_line.h"
#include "../so_long.h"

char	**check_and_store_wall(char *line, char **map, size_t *limit_len)
{
	size_t	w;

	w = 0;
	*limit_len = ft_strlen(line);
	while (*line != '\0')
	{
		if (*line != '1')
			abort_so_long((void *)line);
		map[w][0] = 1;
		w++;
		line++;
	}
	return (map);
}

char	**check_and_store_area(char *line, char **map, size_t h)
{
	size_t	w;
	char	*start;

	start = line;
	w = 0;
	// 左端がwallであるか
	if (*line != '1')
		abort_so_long((void *)start);
	map[w++][h] = *line++;
	while (*line != '\0')
	{
		map[w++][h] = *line;
		line++;
	}
	// 右端がwallであるか
	if (--(*line) != '1')
		abort_so_long((void *)start);
	
}

int	validate_and_store_map(char *map_path, char **map)
{
	int		fd;
	char	*line;
	size_t	limit_len;
	int		status;
	size_t	h;

	status = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		abort_so_long(NULL);
	line = get_next_line(fd, &status);
	if (status == -1)
		abort_so_long((void *)line);
	map = check_wall(line, map, &limit_len);
	// 一回取り込んでから壁判定するのが良さそう
	h = 1;
	while (line != NULL)
	{
		line = get_next_line(fd, status);
		if (status == -1)
			abort_so_long((void *)line);
		// topの長さと他の長さが、違っていたらabort
		if (limit_len != ft_strlen(line))
			abort_so_long((void *)line);
		map = check_and_store_area(line, map, h);
		h++;
	}
	
}



int	main()
{
	size_t **map;

	validate_and_store_map("files/line", map);
	return (0);
}

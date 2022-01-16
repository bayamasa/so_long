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
		map[h] = line;
		h++;
	}
	return (map);
}

int	is_line_same_length(char **map, int line_num)
{
	size_t	w;
	size_t	h;
	size_t	top_len;
	size_t	len;

	w = 0;
	h = 0;
	top_len = ft_strlen(map[h++]);
	while (h < line_num)
	{
		len = ft_strlen(map[h]);
		if (h == line_num - 1)
		{
			// 最後の行は改行がないので -1
			if (top_len != len + 1)
				return (false);
		}
		else
		{
			if (top_len != len)
				return (false);
		}
		h++;
	}
	return (true);
}

int	is_top_and_end_only_wall(char **map, int line_num)
{
	size_t	j;

	j = 0;
	while (map[0][j] != '\n')
	{
		if (map[0][j] != '1')
			return (false);
		j++;
	}
	j = 0;
	while (map[line_num - 1][j] != '\0')
	{
		if (map[line_num - 1][j] != '1')
			return (false);
		j++;
	}	
	return (true);
}

int	is_area_surrounded_wall(char **map, int	line_num)
{
	size_t	h;
	size_t	top_len;

	top_len = ft_strlen(map[0]);
	h = 1;
	while (h < line_num)
	{
		if (map[h][0] != '1')
		{
			return (false);
		}
		if (map[h][top_len - 2] != '1')
		{
			return (false);
		}
		h++;
	}
	return (true);
}

int	is_included(char *line, char chara)
{
	size_t	i;
	size_t	len;
	size_t	chara_count;

	i = 0;
	len = ft_strlen(line);
	chara_count = 0;
	while (i < len)
	{
		if (line[i] == chara)
		{
			chara_count++;
		}
		i++;
	}
	return (chara_count);
}

int	is_valid_area(char **map, int line_num)
{
	size_t	h;
	int		p_count;
	int		c_count;
	int		e_count;

	p_count = 0;
	c_count = 0;
	e_count = 0;
	h = 1;
	while (h < line_num)
	{
		p_count += is_included(map[h], 'P');
		c_count += is_included(map[h], 'C');
		e_count += is_included(map[h], 'E');
		h++;
	}
	if (p_count == 1 && c_count >= 1 && e_count >= 1)
		return (true);
	return (false);
}

int	validate(char **map, int line_num)
{
	int	status;

	if (is_line_same_length(map, line_num))
	{
		if (is_top_and_end_only_wall(map, line_num))
		{
			if (is_area_surrounded_wall(map, line_num))
			{
				if (is_valid_area(map, line_num))
				{
					return (true);
				}
				printf("area\n");
			}
			printf("surrond_wall\n");
		}
		printf("top_end\n");
	}
	printf("line_same_length\n");
	return (false);
}

char	**store_map_from_file(char *filepath)
{
	char	**map;
	size_t	line_num;
	int		status;

	status = 0;
	line_num = count_line_num(filepath);
	// ここのサイズが少なすぎてsegvを起こす。
	// ダブルポインタにおける、map[1]はmap[0]からどれくらい離れているのかをみたい。
	// → NULL止めの参照分のポインタのサイズを忘れていただけ +1して解決。
	map = (char **)malloc(sizeof(char *) * (line_num + 1));
	map = store_all_line(filepath, map);
	status = validate(map, line_num);
	if (status == false)
	{
		printf("validate_error\n");
		abort_so_long(NULL, map);
	}
	return (map);
}

void	put_pixel_by(char **map)
{
	
}


int	main(int argc, char *argv[])
{
	char	**map;
	char	*filepath = "files/line";

	map = store_map_from_file(filepath);
	put_pixel_by(map);
	free_all(NULL, map);
	// print_map(map);
	return (0);
}

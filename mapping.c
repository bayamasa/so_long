/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:01:56 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/16 17:15:01 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_line_num(char *filepath)
{
	size_t	i;
	char	*line;
	int		status;
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		abort_so_long(NULL, NULL);
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
			map[h] = NULL;
			break ;
		}
		map[h] = line;
		h++;
	}
	return (map);
}

void	put_pixel_by(char **map)
{
	
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:54:24 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/21 22:39:43 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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
	if (status == -1)
		abort_sl_with_msg(line, NULL, FILE_READ_ERROR);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd, &status);
		if (status == -1)
			abort_sl_with_msg(line, NULL, FILE_READ_ERROR);
		i++;
	}
	close(fd);
	return (i);
}

int	validate(char **map, size_t line_num, size_t *top_len)
{
	if (has_invalid_attr(map))
		abort_sl_with_msg(NULL, map, INVALID_ATTRIBUTE);
	if (is_map_rectangle(map, line_num, top_len))
	{
		if (is_top_and_end_only_wall(map, line_num))
		{
			if (is_area_surrounded_wall(map, line_num))
			{
				if (is_valid_area(map, line_num))
					return (true);
				abort_sl_with_msg(NULL, map, AREA_ERROR);
			}
			abort_sl_with_msg(NULL, map, AREA_WALL_ERROR);
		}
		abort_sl_with_msg(NULL, map, TOP_OR_END_ERROR);
	}
	abort_sl_with_msg(NULL, map, MAP_SHAPE_ERROR);
	return (false);
}

void	get_screen_size(t_data *data, size_t len, size_t line_num)
{
	int		screen_max_x;
	int		screen_max_y;
	size_t	x;
	size_t	y;

	x = (len - 1) * PIXEL_WIDTH;
	y = line_num * PIXEL_HEIGHT;
	mlx_get_screen_size(data->mlx, &screen_max_x, &screen_max_y);
	if (x > (size_t)screen_max_x || y > (size_t)screen_max_y)
		abort_sl_with_msg(NULL, NULL, INVALID_MAP_SIZE);
	data->win_x = x;
	data->win_y = y;
}

void	init_data(char *filepath, t_data *data)
{
	char	**map;
	size_t	line_num;
	int		status;
	size_t	len;

	status = 0;
	line_num = count_line_num(filepath);
	map = (char **)malloc(sizeof(char *) * (line_num + 1));
	if (map == NULL)
		abort_sl_with_msg(NULL, map, MALLOC_ERROR);
	map = store_all_line(filepath, map);
	status = validate(map, line_num, &len);
	if (status == false)
		abort_sl_with_msg(NULL, map, VALIDATION_ERROR);
	data->map = map;
	init_data_obj(data);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		abort_sl_with_msg(NULL, map, MALLOC_ERROR);
	get_screen_size(data, len, line_num);
	data->mlx_win = mlx_new_window(data->mlx, \
		data->win_x, data->win_y, "so_long");
	if (data->mlx_win == NULL)
		abort_sl_with_msg_free_mlx(data, MALLOC_ERROR);
	init_map_img(data);
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
		abort_sl_with_msg(NULL, map, FILE_NOT_FOUND_ERROR);
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
	close(fd);
	return (map);
}

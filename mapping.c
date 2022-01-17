/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:01:56 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/17 16:30:09 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map_img(void *mlx)
{
	t_map	m;

	m.chara.path = CHARA_PATH;
	m.wall.path = WALL_PATH;
	m.floor.path = FLOOR_PATH;
	m.collective.path = COLLECTIVE_PATH;
	m.exit.path = EXIT_PATH;
	m.chara.img = mlx_xpm_file_to_image(mlx, \
		m.chara.path, &m.chara.width, &m.chara.height);
	m.wall.img = mlx_xpm_file_to_image(mlx, \
		m.wall.path, &m.wall.width, &m.wall.height);
	m.floor.img = mlx_xpm_file_to_image(mlx, \
		m.floor.path, &m.floor.width, &m.floor.height);
	m.collective.img = mlx_xpm_file_to_image(mlx, \
		m.collective.path, &m.collective.width, &m.collective.height);
	m.exit.img = mlx_xpm_file_to_image(mlx, \
		m.exit.path, &m.exit.width, &m.exit.height);
	return (m);
}

void	put_image(t_data data, int width, int height, char map_attr)
{
	if (map_attr == '1')
		mlx_put_image_to_window(data.mlx, \
			data.mlx_win, data.map.wall.img, width, height);
	if (map_attr == '0')
		mlx_put_image_to_window(data.mlx, \
			data.mlx_win, data.map.floor.img, width, height);
	if (map_attr == 'P')
	{
		mlx_put_image_to_window(data.mlx, \
			data.mlx_win, data.map.floor.img, width, height);
		mlx_put_image_to_window(data.mlx, \
			data.mlx_win, data.map.chara.img, width, height);
	}
	if (map_attr == 'C')
		mlx_put_image_to_window(data.mlx, \
			data.mlx_win, data.map.collective.img, width, height);
	if (map_attr == 'E')
		mlx_put_image_to_window(data.mlx, \
			data.mlx_win, data.map.exit.img, width, height);
}

t_data	put_pixel_by(char **map, t_data data)
{
	size_t	w;
	size_t	h;

	w = 0;
	h = 0;
	data.map = init_map_img(data.mlx);
	print_map(map);
	while (map[h] != NULL)
	{
		w = 0;
		while (map[h][w] != '\n' && map[h][w] != '\0')
		{
			put_image(data, w * PIXEL_WIDTH, h * PIXEL_HEIGHT, map[h][w]);
			w++;
		}
		h++;
	}
	return (data);
}

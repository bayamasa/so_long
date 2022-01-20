/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:01:56 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/20 09:19:15 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

t_obj	init_map_img(void *mlx)
{
	t_obj	o;

	o.player.path = PLAYER_PATH;
	o.wall.path = WALL_PATH;
	o.floor.path = FLOOR_PATH;
	o.present.path = PRESENT_PATH;
	o.exit.path = EXIT_PATH;
	o.player.img = mlx_xpm_file_to_image(mlx, \
		o.player.path, &o.player.width, &o.player.height);
	o.wall.img = mlx_xpm_file_to_image(mlx, \
		o.wall.path, &o.wall.width, &o.wall.height);
	o.floor.img = mlx_xpm_file_to_image(mlx, \
		o.floor.path, &o.floor.width, &o.floor.height);
	o.present.img = mlx_xpm_file_to_image(mlx, \
		o.present.path, &o.present.width, &o.present.height);
	o.exit.img = mlx_xpm_file_to_image(mlx, \
		o.exit.path, &o.exit.width, &o.exit.height);
	return (o);
}

void	put_image(t_data data, int width, int height, char map_attr)
{
	if (map_attr == '1')
		mlx_put_image_to_window(data.mlx, \
			data.mlx_win, data.obj.wall.img, width, height);
	if (map_attr == '0')
		mlx_put_image_to_window(data.mlx, \
			data.mlx_win, data.obj.floor.img, width, height);
	if (map_attr == 'P')
	{
		mlx_put_image_to_window(data.mlx, \
			data.mlx_win, data.obj.floor.img, width, height);
		mlx_put_image_to_window(data.mlx, \
			data.mlx_win, data.obj.player.img, width, height);
	}
	if (map_attr == 'C')
		mlx_put_image_to_window(data.mlx, \
			data.mlx_win, data.obj.present.img, width, height);
	if (map_attr == 'E')
		mlx_put_image_to_window(data.mlx, \
			data.mlx_win, data.obj.exit.img, width, height);
}

t_data	put_pixel_by(char **map, t_data data)
{
	size_t	w;
	size_t	h;

	w = 0;
	h = 0;
	data.obj = init_map_img(data.mlx);
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

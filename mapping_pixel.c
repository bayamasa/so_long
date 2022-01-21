/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:01:56 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/21 22:59:19 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_map_img(t_data *d)
{
	d->obj.player.path = PLAYER_PATH;
	d->obj.wall.path = WALL_PATH;
	d->obj.floor.path = FLOOR_PATH;
	d->obj.present.path = PRESENT_PATH;
	d->obj.exit.path = EXIT_PATH;
	d->obj.player.img = mlx_xpm_file_to_image(d->mlx, \
		d->obj.player.path, &d->obj.player.width, &d->obj.player.height);
	if (d->obj.player.img == NULL)
		abort_sl_with_msg_free_mlx(d, MALLOC_ERROR);
	d->obj.wall.img = mlx_xpm_file_to_image(d->mlx, \
		d->obj.wall.path, &d->obj.wall.width, &d->obj.wall.height);
	if (d->obj.wall.img == NULL)
		abort_sl_with_msg_free_mlx(d, MALLOC_ERROR);
	d->obj.floor.img = mlx_xpm_file_to_image(d->mlx, \
		d->obj.floor.path, &d->obj.floor.width, &d->obj.floor.height);
	if (d->obj.floor.img == NULL)
		abort_sl_with_msg_free_mlx(d, MALLOC_ERROR);
	d->obj.present.img = mlx_xpm_file_to_image(d->mlx, \
		d->obj.present.path, &d->obj.present.width, &d->obj.present.height);
	if (d->obj.present.img == NULL)
		abort_sl_with_msg_free_mlx(d, MALLOC_ERROR);
	d->obj.exit.img = mlx_xpm_file_to_image(d->mlx,\
		d->obj.exit.path, &d->obj.exit.width, &d->obj.exit.height);
	if (d->obj.exit.img == NULL)
		abort_sl_with_msg_free_mlx(d, MALLOC_ERROR);
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

int	put_pixel_by(t_data *data)
{
	size_t	w;
	size_t	h;
	char	**map;

	w = 0;
	h = 0;
	map = data->map;
	while (map[h] != NULL)
	{
		w = 0;
		while (map[h][w] != '\n' && map[h][w] != '\0')
		{
			put_image(*data, w * PIXEL_WIDTH, h * PIXEL_HEIGHT, map[h][w]);
			w++;
		}
		h++;
	}
	return (0);
}

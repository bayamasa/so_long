/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:50:37 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/19 10:47:04 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_grid(char **map, int *x, int *y)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	while (map[h] != NULL)
	{
		w = 0;
		while (map[h][w] != '\0' && map[h][w] != '\n')
		{
			if (map[h][w] == 'P')
			{
				*x = w;
				*y = h;
			}
			w++;
		}
		h++;
	}
}

void	move_player_grid(int code, char **map, int x, int y)
{
	map[y][x] = '0';
	if (code == UP)
		map[y - 1][x] = 'P';
	if (code == DOWN)
		map[y + 1][x] = 'P';
	if (code == RIGHT)
	{
		map[y][x + 1] = 'P';
	}
	if (code == LEFT)
	{
		map[y][x - 1] = 'P';
	}
}

void	rerender_player(int code, t_data *d)
{
	int	x;
	int	y;

	get_player_grid(d->map, &x, &y);
	mlx_put_image_to_window(d->mlx, \
			d->mlx_win, d->obj.floor.img, x * 50, y * 50);
	if (code == UP)
		mlx_put_image_to_window(d->mlx, \
			d->mlx_win, d->obj.player.img, x * 50, (y - 1) * 50);
	if (code == DOWN)
		mlx_put_image_to_window(d->mlx, \
			d->mlx_win, d->obj.player.img, x * 50, (y + 1) * 50);
	if (code == RIGHT)
		mlx_put_image_to_window(d->mlx, \
			d->mlx_win, d->obj.player.img, (x + 1) * 50, y * 50);
	if (code == LEFT)
		mlx_put_image_to_window(d->mlx, \
			d->mlx_win, d->obj.player.img, (x - 1) * 50, y * 50);
	move_player_grid(code, d->map, x, y);
}

void	process_player_action(int direction, t_data *data)
{
	if (!is_obj_in_the(direction, *data, WALL))
	{
		if (is_obj_in_the(direction, *data, PRESENT))
		{
			data->obj.player.collect_count++;
			printf("present collect!\n");
		}
		if (is_obj_in_the(direction, *data, EXIT))
		{
			if (data->obj.present.num_in_map == 0)
			{
				printf("player GOAL\n");
				exit(0);
			}
			else
			{
				printf("player need to collect present\n");
				return ;
			}
		}
		rerender_player(direction, data);
	}
	store_present_num(data, (*data).map);
}
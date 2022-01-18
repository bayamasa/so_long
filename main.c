/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:02:44 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/18 09:12:03 by mhirabay         ###   ########.fr       */
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

int	is_wall_in_the_direction(int code, t_data d)
{
	int	x;
	int	y;

	get_player_grid(d.map, &x, &y);
	if (code == UP)
		// x座標そのまま。y座標一つ上
		if (d.map[y - 1][x] == '1')
			return (true);
	if (code == DOWN)
		// x座標そのまま。y座標一つ上
		if (d.map[y + 1][x] == '1')
			return (true);
	if (code == RIGHT)
		if (d.map[y][x + 1] == '1')
			return (true);
	if (code == LEFT)
		if (d.map[y][x - 1] == '1')
			return (true);
	return (false);
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
	// printf("x = %d\n", x);
	// printf("y = %d\n", y);
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

int	move_player_hook(int keycode, void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
	{
		if (!is_wall_in_the_direction(UP, *d))
		{
			printf("player UP\n");
			rerender_player(UP, d);
		}
	}
	if (keycode == KEY_S)
	{
		if (!is_wall_in_the_direction(DOWN, *d))
		{
			printf("player DOWN\n");
			rerender_player(DOWN, d);
		}
	}
	if (keycode == KEY_A)
	{
		if (!is_wall_in_the_direction(LEFT, *d))
		{
			printf("player LEFT\n");
			rerender_player(LEFT, d);
		}
	}
	if (keycode == KEY_D)
	{
		if (!is_wall_in_the_direction(RIGHT, *d))
		{
			printf("player RIGHT\n");
			rerender_player(RIGHT, d);
		}
	}
	printf("hook_end\n");
	print_map(d->map);
	return (0);
}

int	main(void)
{
	t_data	data;
	char	*filepath;
	char	**map;
	void 	*mlx;
	void 	*mlx_win;

	//strcatで結合するよてい
	filepath = "map/normal.ber";
	data.map = store_map_from_file(filepath);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 400, 400, "so_long");
	data = put_pixel_by(data.map, data);
	mlx_hook(data.mlx_win, X_EVENT_KEY_PRESS, 0, move_player_hook, &data);
	mlx_loop(data.mlx);
	// free_all(NULL, map);
}

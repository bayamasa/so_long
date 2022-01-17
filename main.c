/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:02:44 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/17 20:19:25 by mhirabay         ###   ########.fr       */
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
		while (map[h][w] != '\0' || map[h][w] != '\n' )
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

	print_map(d.map);
	get_player_grid(d.map, &x, &y);
	if (code == UP)
		// x座標そのまま。y座標一つ上
		if (d.map[x][y - 1] == '1')
			return (true);
	if (code == DOWN)
		// x座標そのまま。y座標一つ上
		if (d.map[x][y + 1] == '1')
			return (true);
	if (code == RIGHT)
		if (d.map[x + 1][y] == '1')
			return (true);
	if (code == LEFT)
		if (d.map[x - 1][y] == '1')
			return (true);
	return (false);
}

void	rerender_player(int code, t_data d)
{
	int	x;
	int	y;

	get_player_grid(d.map, &x, &y);
	mlx_put_image_to_window(d.mlx, \
			d.mlx_win, d.obj.floor.img, x * 50, y * 50);
	if (code == UP)
		mlx_put_image_to_window(d.mlx, \
			d.mlx_win, d.obj.player.img, x * 50, (y - 1) * 50);
	if (code == DOWN)
		mlx_put_image_to_window(d.mlx, \
			d.mlx_win, d.obj.player.img, x * 50, (y + 1) * 50);	
	if (code == RIGHT)
		mlx_put_image_to_window(d.mlx, \
			d.mlx_win, d.obj.player.img, (x + 1) * 50, y * 50);
	if (code == LEFT)
		mlx_put_image_to_window(d.mlx, \
			d.mlx_win, d.obj.player.img, (x - 1) * 50, y * 50);
}

int	move_player_hook(int keycode, void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		if (!is_wall_in_the_direction(UP, *d))
			rerender_player(UP, *d);
	if (keycode == KEY_S)
		if (!is_wall_in_the_direction(DOWN, *d))
			rerender_player(UP, *d);
	if (keycode == KEY_A)
		if (!is_wall_in_the_direction(LEFT, *d))
			rerender_player(LEFT, *d);
	if (keycode == KEY_D)
		if (!is_wall_in_the_direction(RIGHT, *d))
			rerender_player(RIGHT, *d);
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
	filepath = "map/test.ber";
	data.map = store_map_from_file(filepath);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 400, 400, "so_long");
	data = put_pixel_by(data.map, data);
	print_map(data.map);
	mlx_hook(data.mlx_win, X_EVENT_KEY_PRESS, 0, move_player_hook, &data);
	mlx_loop(data.mlx);
	// free_all(NULL, map);
}

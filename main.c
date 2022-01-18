/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:02:44 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/18 13:48:17 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	do_player_keyhook(int keycode, void *data)
{
	t_data	*d;

	d = (t_data *)data;
	d->obj.player.collect_count = 0;
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		process_player_action(UP, d);
	if (keycode == KEY_S)
		process_player_action(DOWN, d);
	if (keycode == KEY_A)
		process_player_action(LEFT, d);
	if (keycode == KEY_D)
		process_player_action(RIGHT, d);
	print_map(d->map);
	store_present_num(d, (*d).map);
	printf("d->obj.present.num_in_map = %zu\n", d->obj.present.num_in_map);
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
	data.mlx_win = mlx_new_window(data.mlx, 800, 800, "so_long");
	data = put_pixel_by(data.map, data);
	mlx_hook(data.mlx_win, X_EVENT_KEY_PRESS, 0, do_player_keyhook, &data);
	mlx_loop(data.mlx);
	// free_all(NULL, map);
}

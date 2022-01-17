/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:02:44 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/17 16:05:59 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	test_key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_W)
	{
		printf("W pressed\n");
	}
	else if (keycode == KEY_S)
	{
		printf("S pressed\n");
		// mlx_destroy_image()
	}
	else if (keycode == KEY_A)
	{
		printf("A pressed\n");
	}
	else if (keycode == KEY_D)
	{
		printf("D pressed\n");
	}
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	main(void)
{
	t_data	*data;
	char	*filepath;
	char	**map;
	void 	*mlx;
	void 	*mlx_win;

	//strcatで結合するよてい
	filepath = "map/test.ber";
	map = store_map_from_file(filepath);
	data = (t_data *)malloc(sizeof(t_data));
	data->mlx = mlx_init();
	mlx_win = mlx_new_window(data->mlx, 400, 400, "so_long");
	put_pixel_by(map, data);
	mlx_hook(data->mlx_win, X_EVENT_KEY_PRESS, 0, test_key_hook, data);
	mlx_loop(data->mlx);
	// free_all(NULL, map);
}

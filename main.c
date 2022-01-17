/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:02:44 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/17 19:51:25 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	is_wall_in_the_direction(int code, t_data d)
{
	
}


void	rerender_player(int code, t_data d)
{
	
}

int	move_chara_hook(int keycode, void *data)
{
	t_data	*d;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	d = (t_data *)data;
	// addr = mlx_get_data_addr(d->map.wall.img, &bits_per_pixel, &line_length, &endian);
	// printf("addr : %s\n", addr);
	// printf("bits_per_pixel = %d\n", bits_per_pixel);
	// printf("line_length = %d\n", line_length);
	// printf("endian = %d\n", endian);
	// 方針 charaのアドレスをget_addrで取ってきて、50pixel移動した場所に対して再描画を行う。
	// これはできない。なぜならget_addrでとってこれるのはimgに対する情報だけだから。
	// どこに描画したかまでは確認できない
	// その際に、元々あったchara画像のインスタンスはfreeする。→ しなくても良いかも？
	// putしたimageを削除することはできないので、上書きする方針とする。
	if (keycode == KEY_W)
	{
		printf("W pressed\n");
		rerender_player(UP, *d);
	}
	else if (keycode == KEY_S)
	{
		printf("S pressed\n");
		rerender_player(UP, *d);
	}
	else if (keycode == KEY_A)
	{
		printf("A pressed\n");
		rerender_player(UP, *d);
	}
	else if (keycode == KEY_D)
	{
		printf("D pressed\n");
		rerender_player(UP, *d);
	}
	else if (keycode == KEY_ESC)
		exit(0);
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
	map = store_map_from_file(filepath);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 400, 400, "so_long");
	data = put_pixel_by(map, data);
	mlx_hook(data.mlx_win, X_EVENT_KEY_PRESS, 0, move_chara_hook, &data);
	mlx_loop(data.mlx);
	// free_all(NULL, map);
}

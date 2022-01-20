/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:02:44 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/20 20:53:53 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	char	*filepath;

	check_args(argc, argv, &filepath);
	init_data(filepath, &data);
	put_pixel_by(&data);
	mlx_key_hook(data.mlx_win, do_player_keyhook, &data);
	mlx_hook(data.mlx_win, X_EVENT_KEY_EXIT, 0, exit_game, &data);
	mlx_expose_hook(data.mlx_win, put_pixel_by, &data);
	mlx_loop(data.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:51:41 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/20 20:52:19 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	exit_game(t_data *data)
{
	printf("game closing...\n");
	free_all(NULL, data->map);
	if (data->obj.wall.img != NULL)
		mlx_destroy_image(data->mlx, data->obj.wall.img);
	if (data->obj.floor.img != NULL)
		mlx_destroy_image(data->mlx, data->obj.floor.img);
	if (data->obj.present.img != NULL)
		mlx_destroy_image(data->mlx, data->obj.present.img);
	if (data->obj.player.img != NULL)
		mlx_destroy_image(data->mlx, data->obj.player.img);
	if (data->obj.exit.img != NULL)
		mlx_destroy_image(data->mlx, data->obj.exit.img);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		mlx_loop_end(data->mlx);
	}
	free(data->mlx);
	exit(0);
}

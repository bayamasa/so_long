/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:02:44 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/19 13:26:31 by mhirabay         ###   ########.fr       */
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
	return (0);
}

int	exit_game(int keycode, t_data *data)
{
	printf("process terminating...\n");
	exit(0);
}

int	is_valid_extension(const char *filepath, const char *ext)
{
	size_t		ext_len;
	size_t		i;
	size_t		j;

	ext_len = ft_strlen(ext);
	i = 0;
	j = 0;
	if (ft_strlen(filepath) == ext_len)
		return (false);
	while (filepath[i] != '\0')
		i++;
	while (j < ext_len)
	{
		i--;
		j++;
	}
	if (ft_strncmp(filepath + i, ext, ext_len))
		return (false);
	return (true);
}

void	check_args(int argc, char *argv[], char **filepath)
{
	const char	*ext;

	ext = ".ber";
	if (argc != 2)
		abort_sl_with_msg(NULL, NULL, INVALID_ARGS_NUM);
	if (!is_valid_extension(argv[1], ext))
		abort_sl_with_msg(NULL, NULL, INVALID_FILENAME);
	*filepath = argv[1];
	return ;
}

int	main(int argc, char *argv[])
{
	t_data	data;
	char	*filepath;

	check_args(argc, argv, &filepath);
	data = init_data(filepath);
	data = put_pixel_by(data.map, data);
	mlx_key_hook(data.mlx_win, do_player_keyhook, &data);
	mlx_hook(data.mlx_win, X_EVENT_KEY_EXIT, 0, exit_game, &data);
	mlx_loop(data.mlx);
	// free_all(NULL, map);
}

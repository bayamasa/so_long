/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:09:30 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/22 13:51:23 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	free_all(char *line, char **map)
{
	size_t	i;

	i = 0;
	if (line != NULL)
	{
		free(line);
	}
	if (map != NULL)
	{
		while (map[i] != NULL)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	abort_so_long(char *line, char **map)
{
	if (line != NULL || map != NULL)
	{
		free_all(line, map);
	}
	ft_putstr_fd(ERROR, STDERR_FILENO);
	exit(1);
}

void	print_error(void)
{
	ft_putstr_fd(ERROR, STDERR_FILENO);
}

void	abort_sl_with_msg(char *line, char **map, char *msg)
{
	if (line != NULL || map != NULL)
	{
		free_all(line, map);
	}
	print_error();
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(1);
}

void	abort_sl_with_msg_free_mlx(t_data *data, char *msg)
{
	free_data(data);
	print_error();
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(1);
}

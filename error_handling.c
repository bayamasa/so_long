/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:09:30 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/20 20:56:02 by mhirabay         ###   ########.fr       */
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
	printf(ERROR);
	exit(1);
}

void	print_error(void)
{
	ft_putstr_fd(ERROR, 2);
}

void	abort_sl_with_msg(char *line, char **map, char *msg)
{
	if (line != NULL || map != NULL)
	{
		free_all(line, map);
	}
	print_error();
	ft_putstr_fd(msg, 2);
	exit(1);
}
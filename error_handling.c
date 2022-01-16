/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:09:30 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/16 16:07:25 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// ちゃんと全部の値がfreeできているかテストする
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

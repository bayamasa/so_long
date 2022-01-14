/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:09:30 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/14 13:51:27 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// ちゃんと全部の値がfreeできているかテストする
void	free_all(char *line, char **map)
{
	if (line != NULL)
		free(line);
	if (map != NULL)
	{
		while (*map != NULL)
		{
			free(*map);
			(*map)++;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:24:15 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/18 13:55:09 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	store_present_num(t_data *d, char **map)
{
	size_t	w;
	size_t	h;
	size_t	count;

	w = 0;
	h = 0;
	count = 0;
	while (map[h] != NULL)
	{
		w = 0;
		while (map[h][w] != '\0' && map[h][w] != '\n')
		{
			if (map[h][w] == 'C')
			{
				count++;
			}
			w++;
		}
		h++;
	}
	d->obj.present.num_in_map = count;
}

int	is_obj_in_the(int direction, t_data d, char obj)
{
	int	x;
	int	y;

	get_player_grid(d.map, &x, &y);
	if (direction == UP)
		if (d.map[y - 1][x] == obj)
			return (true);
	if (direction == DOWN)
		if (d.map[y + 1][x] == obj)
			return (true);
	if (direction == RIGHT)
		if (d.map[y][x + 1] == obj)
			return (true);
	if (direction == LEFT)
		if (d.map[y][x - 1] == obj)
			return (true);
	return (false);
}

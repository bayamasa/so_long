/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:24:15 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/18 09:57:36 by mhirabay         ###   ########.fr       */
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

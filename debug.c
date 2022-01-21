/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:52:52 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/22 06:55:18 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	print_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("line : %s\n", map[i]);
		i++;
	}
}

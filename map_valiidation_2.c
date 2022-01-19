/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valiidation_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:17:21 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/19 14:17:33 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_included(char *line, char chara)
{
	size_t	i;
	size_t	len;
	size_t	chara_count;

	i = 0;
	len = ft_strlen(line);
	chara_count = 0;
	while (i < len)
	{
		if (line[i] == chara)
		{
			chara_count++;
		}
		i++;
	}
	return (chara_count);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:05:34 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/16 17:08:48 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_line_same_length(char **map, int line_num)
{
	size_t	w;
	size_t	h;
	size_t	top_len;
	size_t	len;

	w = 0;
	h = 0;
	top_len = ft_strlen(map[h++]);
	while (h < line_num)
	{
		len = ft_strlen(map[h]);
		if (h == line_num - 1)
		{
			if (top_len != len + 1)
				return (false);
		}
		else
		{
			if (top_len != len)
				return (false);
		}
		h++;
	}
	return (true);
}

int	is_top_and_end_only_wall(char **map, int line_num)
{
	size_t	j;

	j = 0;
	while (map[0][j] != '\n')
	{
		if (map[0][j] != '1')
			return (false);
		j++;
	}
	j = 0;
	while (map[line_num - 1][j] != '\0')
	{
		if (map[line_num - 1][j] != '1')
			return (false);
		j++;
	}	
	return (true);
}

int	is_area_surrounded_wall(char **map, int	line_num)
{
	size_t	h;
	size_t	top_len;

	top_len = ft_strlen(map[0]);
	h = 1;
	while (h < line_num)
	{
		if (map[h][0] != '1')
		{
			return (false);
		}
		if (map[h][top_len - 2] != '1')
		{
			return (false);
		}
		h++;
	}
	return (true);
}

int	is_valid_area(char **map, int line_num)
{
	size_t	h;
	int		p_count;
	int		c_count;
	int		e_count;

	p_count = 0;
	c_count = 0;
	e_count = 0;
	h = 1;
	while (h < line_num)
	{
		p_count += is_included(map[h], 'P');
		c_count += is_included(map[h], 'C');
		e_count += is_included(map[h], 'E');
		h++;
	}
	if (p_count == 1 && c_count >= 1 && e_count >= 1)
		return (true);
	return (false);
}

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
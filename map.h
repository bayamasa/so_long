/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:09:36 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/17 14:32:04 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define CHARA_PATH "./img/chara.xpm"
# define WALL_PATH "./img/wall.xpm"
# define FLOOR_PATH "./img/floor.xpm"
# define COLLECTIVE_PATH "./img/collective.xpm"
# define EXIT_PATH "./img/exit.xpm"
# define PIXEL_WIDTH 50
# define PIXEL_HEIGHT 50

typedef struct s_chara
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}		t_chara;

typedef struct s_wall
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}		t_wall;

typedef struct s_floor
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}		t_floor;

typedef struct s_collective
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}		t_collective;

typedef struct s_exit
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}		t_exit;

typedef struct s_map
{
	t_chara			chara;
	t_wall			wall;
	t_floor			floor;
	t_collective	collective;
	t_exit			exit;
}		t_map;

#endif
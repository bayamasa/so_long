/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:09:36 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/18 13:34:43 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# define PLAYER_PATH "./img/player.xpm"
# define WALL_PATH "./img/wall.xpm"
# define FLOOR_PATH "./img/floor.xpm"
# define PRESENT_PATH "./img/present.xpm"
# define EXIT_PATH "./img/exit.xpm"

# define PLAYER 'P'
# define WALL '1'
# define FLOOR '0'
# define PRESENT 'P'
# define EXIT 'E'

# define PIXEL_WIDTH 50
# define PIXEL_HEIGHT 50

typedef struct s_player
{
	void	*img;
	char	*path;
	int		width;
	int		height;
	size_t	collect_count;
}		t_player;

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

typedef struct s_present
{
	void	*img;
	char	*path;
	int		width;
	int		height;
	size_t	num_in_map;
}		t_present;

typedef struct s_exit
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}		t_exit;

typedef struct s_obj
{
	t_player	player;
	t_wall		wall;
	t_floor		floor;
	t_present	present;
	t_exit		exit;
}		t_obj;

#endif
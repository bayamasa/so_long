#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include "lib/ft_printf/ft_printf.h"
# include "lib/gnl/get_next_line.h"
# include "map.h"
# include "lib/mlx/mlx.h"

# define ERROR "Error\n"

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	t_map	map;
}		t_data;

void	abort_so_long(char *line, char **map);
void	free_all(char *line, char **map);

int		is_line_same_length(char **map, int line_num);
int		is_top_and_end_only_wall(char **map, int line_num);
int		is_area_surrounded_wall(char **map, int	line_num);
int		is_valid_area(char **map, int line_num);
int		is_included(char *line, char chara);

size_t	count_line_num(char *filepath);
int		validate(char **map, int line_num);
char	**store_map_from_file(char *filepath);
char	**store_all_line(char *filepath, char **map);
void	put_pixel_by(char **map, t_data data);
void	print_map(char **map);

#endif
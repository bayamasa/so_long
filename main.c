#include "lib/mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	char	*path;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_width;
	int		img_height;
	t_data	chara;
	t_data	wall;
	t_data	floor;
	char 	filepath;
	char 	**map;

	//strcatで結合するよてい
	filepath = "map/test.ber";
	map = store_map_from_file(filepath);
	put_pixel_by(map);
	free_all(NULL, map);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "so_long");
	chara.path = "./chara.xpm";
	chara.img = mlx_xpm_file_to_image(mlx, chara.path, &chara.bits_per_pixel, &chara.line_length);
	wall.path = "./kabe.xpm";
	wall.img = mlx_xpm_file_to_image(mlx, wall.path, &wall.bits_per_pixel, &wall.line_length);
	// chara.addr = 


	mlx_put_image_to_window(mlx, mlx_win, wall.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 50, 0);

	mlx_put_image_to_window(mlx, mlx_win, chara.img, 50, 0);
	mlx_loop(mlx);
}

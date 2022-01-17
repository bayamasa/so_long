
#include "so_long.h"



int	main(void)
{
	t_data	data;
	char	*filepath;
	char	**map;

	//strcatで結合するよてい
	filepath = "map/test.ber";
	map = store_map_from_file(filepath);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 400, 400, "so_long");
	put_pixel_by(map, data);
	// chara.path = "./chara.xpm";
	// chara.img = mlx_xpm_file_to_image(mlx, chara.path, &chara.bits_per_pixel, &chara.line_length);
	// wall.path = "./kabe.xpm";
	// wall.img = mlx_xpm_file_to_image(mlx, wall.path, &wall.bits_per_pixel, &wall.line_length);
	// // chara.addr = 

	// mlx_put_image_to_window(mlx, mlx_win, wall.img, 0, 0);
	// mlx_put_image_to_window(mlx, mlx_win, wall.img, 50, 0);

	// mlx_put_image_to_window(mlx, mlx_win, chara.img, 50, 0);
	mlx_loop(data.mlx);
	// free_all(NULL, map);
}

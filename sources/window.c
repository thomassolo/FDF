#include <stdlib.h>
#include "fdf.h"
#include "minilibx-linux/mlx.h"


int	main(int ac, char **av)
{
	
	mlx_data *win;
	win = malloc(sizeof(mlx_data));
	
	char *filename;
	read_file1(av[1], win);
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, 1000, 1000, "Hello world!");
	win->img = mlx_new_image(win->mlx, 1000, 1000);
	win->zoom = 20;
	win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel, &win->line_length, &win->endian);
	ft_draw(win);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
	mlx_loop(win->mlx);
}
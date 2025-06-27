#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	data;

	params(&data, ac, av);
	data.zoom = 1.5;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "sas");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img,
			&data.bits_per_pixel, &data.line_length, &data.endian);
	render(&data);
	mlx_hook(data.win, 17, 0, clean_exit, &data);
	mlx_key_hook(data.win, xddkey, &data);
	mlx_mouse_hook(data.win, xddmouse, &data);
	mlx_loop(data.mlx);
	return (0);
}

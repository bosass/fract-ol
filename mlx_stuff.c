#include "fractol.h"

int	clean_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	exit(0);
}

int	xddkey(int keycode, t_data *data)
{
	if (keycode == 65307)
		clean_exit(data);
	else if (keycode == 65361)
		data->shiftx -= data->zoom / 4;
	else if (keycode == 65363)
		data->shiftx += data->zoom / 4;
	else if (keycode == 65362)
		data->shifty += data->zoom / 4;
	else if (keycode == 65364)
		data->shifty -= data->zoom / 4;
	render(data);
	return (0);
}

int	xddmouse(int button, int x, int y, t_data *data)
{
	if (button == 4)
		data->zoom *= 0.6;
	else if (button == 5)
		data->zoom = data->zoom / 0.6;
	render(data);
	(void)x;
	(void)y;
	return (0);
}

void	friendly_reminder(void)
{
	write(1, "use one of these parameters:\n", 29);
	write(1, "mandelbrot\njulia <n> <n>\nburn\n", 30);
	exit (0);
}

void	params(t_data *data, int ac, char **av)
{
	if (ac >= 2)
	{
		if (!ft_strncmp(av[1], "mandelbrot", 10))
			data->ftype = "mandelbrot";
		else if (!ft_strncmp(av[1], "burn", 4))
			data->ftype = "burn";
		else if (!ft_strncmp(av[1], "julia", 5))
		{
			if (ac >= 4)
			{
				data->ftype = "julia";
				data->jrl = ft_atof(av[2]);
				data->jim = ft_atof(av[3]);
			}
			else
				friendly_reminder();
		}
		else
			friendly_reminder();
	}
	else
		friendly_reminder();
}

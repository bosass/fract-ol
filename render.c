#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	render_mandelbrot(t_data *data)
{
	int				x;
	int				y;
	unsigned int	color;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = ft_color(mandelbrot(x, y, data), x, y);
			if (!color)
				color = ft_color(mandelbrot_in(x, y, data), y, x);
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	render_julia(t_data *data)
{
	int				x;
	int				y;
	unsigned int	color;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = julia(x, y, data) * 13;
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	render_burn(t_data *data)
{
	int				x;
	int				y;
	unsigned int	color;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = burn(x, y, data) * 13;
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	render(t_data *data)
{
	if (!ft_strncmp(data->ftype, "mandelbrot", 10))
		render_mandelbrot(data);
	if (!ft_strncmp(data->ftype, "julia", 5))
		render_julia(data);
	if (!ft_strncmp(data->ftype, "burn", 4))
		render_burn(data);
}

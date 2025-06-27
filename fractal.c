#include "fractol.h"

unsigned int	mandelbrot(int x, int y, t_data *data)
{
	t_complex		c;
	t_complex		z;
	unsigned int	i;

	c.x = map(x, -data->zoom + data->shiftx,
			data->zoom + data->shiftx, WIDTH);
	c.y = map(y, data->zoom + data->shifty,
			-data->zoom + data->shifty, HEIGHT);
	z = c;
	i = 0;
	while (i < ITERATIONS)
	{
		if (chyp(c) >= ESC)
			return (i);
		c = cadd(csqr(c), z);
		i++;
	}
	return (0);
}

unsigned int	mandelbrot_in(int x, int y, t_data *data)
{
	t_complex		c;
	t_complex		z;
	unsigned int	i;
	double			out;

	c.x = map(x, -data->zoom + data->shiftx,
			data->zoom + data->shiftx, WIDTH);
	c.y = map(y, data->zoom + data->shifty,
			-data->zoom + data->shifty, HEIGHT);
	z = c;
	i = 0;
	out = 0;
	while (i < ITERATIONS)
	{
		if (chyp(c) >= ESC)
			return (0);
		else if (chyp(c) > out)
			out = chyp(c);
		c = cadd(csqr(c), z);
		i++;
	}
	i = map(out, 0, ITERATIONS, 4);
	return (i);
}

unsigned int	julia(int x, int y, t_data *data)
{
	t_complex		c;
	t_complex		z;
	unsigned int	i;

	c.x = map(x, -data->zoom + data->shiftx,
			data->zoom + data->shiftx, WIDTH);
	c.y = map(y, data->zoom + data->shifty,
			-data->zoom + data->shifty, HEIGHT);
	z.x = data->jrl;
	z.y = data->jim;
	i = 0;
	while (i < ITERATIONS)
	{
		if (chyp(c) >= ESC)
			return (i);
		c = cadd(csqr(c), z);
		i++;
	}
	return (i);
}

int	burn(int x, int y, t_data *data)
{
	t_complex		c;
	t_complex		z;
	unsigned int	i;

	c.x = map(x, -data->zoom + data->shiftx,
			data->zoom + data->shiftx, WIDTH);
	c.y = map(y, -data->zoom - data->shifty,
			data->zoom - data->shifty, HEIGHT);
	z = c;
	i = 0;
	while (i < ITERATIONS)
	{
		if (chyp(c) >= ESC)
			return (i);
		c.x = absv(c.x);
		c.y = absv(c.y);
		c = cadd(csqr(c), z);
		i++;
	}
	return (0);
}

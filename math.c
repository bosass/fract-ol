#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

double	powerof(int x)
{
	double	i;

	i = 1;
	while (x > 1)
	{
		i = i * 10;
		x--;
	}
	return (i);
}

unsigned int	ft_color(unsigned int c, int x, int y)
{
	if (c == 0)
		return (0);
	return (c * ((y - x) * 50));
}

unsigned int	ft_color_in(unsigned int c, int x, int y)
{
	if (c == 0)
		return (0);
	return (c * ((y - x) * 50));
}

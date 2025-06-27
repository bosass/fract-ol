#include "fractol.h"

t_complex	csqr(t_complex c)
{
	t_complex	out;

	out.x = (c.x * c.x) - (c.y * c.y);
	out.y = c.y * c.x * 2;
	return (out);
}

t_complex	cadd(t_complex c1, t_complex c2)
{
	t_complex	out;

	out.x = c1.x + c2.x;
	out.y = c1.y + c2.y;
	return (out);
}

double	absv(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

double	chyp(t_complex c)
{
	return (c.x * c.x + (c.y * c.y));
}

#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# define SIZE 50
# define RED 0x00FF0000
# define WIDTH 800
# define HEIGHT 800
# define ITERATIONS 42
# define ESC 4
# define INCOLOR 0x00010101
# define COLORSHIFT 10
# define WHITE 0x00FFFFFF
# define BLUE 0x000000FF
# define LYL 0x005D10A1
# define PINK 0x00ed11d7
# define BLACK 0

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*ftype;
	double	jrl;
	double	jim;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	shiftx;
	double	shifty;
	double	zoom;
}				t_data;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

unsigned int	mandelbrot(int x, int y, t_data *data);
unsigned int	mandelbrot_in(int x, int y, t_data *data);
unsigned int	julia(int x, int y, t_data *data);
int				burn(int x, int y, t_data *data);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
double			ft_atof(const char *str);
t_complex		csqr(t_complex c);
t_complex		cadd(t_complex c1, t_complex c2);
double			absv(double n);
double			chyp(t_complex c);
double			map(double unscaled_num, double new_min,
					double new_max, double old_max);
double			powerof(int x);
unsigned int	ft_color(unsigned int c, int x, int y);
unsigned int	ft_color_in(unsigned int c, int x, int y);
int				clean_exit(t_data *data);
int				xddkey(int keycode, t_data *data);
int				xddmouse(int button, int x, int y, t_data *data);
void			friendly_reminder(void);
void			params(t_data *data, int ac, char **av);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			render_mandelbrot(t_data *data);
void			render_julia(t_data *data);
void			render_burn(t_data *data);
void			render(t_data *data);
#endif
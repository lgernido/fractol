/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:39:03 by lgernido          #+#    #+#             */
/*   Updated: 2024/01/09 14:32:10 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_draw
{
	char	*fractal_type;
	char	*palette;
	double	zoom;
	double	real;
	double	imaginary;
	double	x;
	double	y;
	double	a;
	double	b;
	double	cx;
	double	cy;
	double	x_mouse;
	double	y_mouse;
}			t_draw;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_draw	draw;
}			t_data;

int			main(int argc, char **argv);

/*Initialisation*/

t_data		ft_init(t_data *data);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		struct_init(t_data *data, int argc, char **argv);

/*Gestion des evenements*/

int			close_win(t_data *data);
void		ft_shift_fractal(t_data *data);
int			handle_keypress(int keysym, t_data *data);
int			handle_mousepress(int button, int x, int y, t_data *data);
void		handle_events(t_data *data);

/*Dessin de Mandelbrot*/

void		draw_mandelbrot(t_data *data);
void		compute_mandelbrot(t_data *data, double x, double y);

/*Dessin de Julia*/

void		draw_julia(t_data *data);
void		compute_julia(t_data *data, double x, double y);

/*Dessin du Burning ship*/

void		draw_burningship(t_data *data);
void		compute_burning(t_data *data, double x, double y);

/*Traitement des parametres*/

void		display_help(t_data *data);
void		choose_fractal(int argc, char **argv, t_data *data);
void		set_fractal_type(t_data *data, char *fractal_type, int argc);
double		ft_atod(char *nptr);
void		check_params(int argc, char **argv, t_data *data);

/*Gestion des couleurs*/

uint32_t	find_color(int n, t_data *data);
void		ft_shift_color(t_data *data);

#endif
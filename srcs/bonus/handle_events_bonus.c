/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:23:13 by lgernido          #+#    #+#             */
/*   Updated: 2024/01/10 09:14:54 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_shift_fractal(t_data *data)
{
	if (ft_strncmp(data->draw.fractal_type, "m", 1) == 0)
		data->draw.fractal_type = "b";
	else if (ft_strncmp(data->draw.fractal_type, "b", 1) == 0)
		data->draw.fractal_type = "m";
}

int	close_win(t_data *data)
{
	if (data->mlx && data->win)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_win(data);
	else if (keycode == XK_Up)
		data->draw.y += 0.01;
	else if (keycode == XK_Down)
		data->draw.y -= 0.01;
	else if (keycode == XK_Left)
		data->draw.x += 0.01;
	else if (keycode == XK_Right)
		data->draw.x -= 0.01;
	else if (keycode == XK_c)
		ft_shift_color(data);
	else if (keycode == XK_f)
		ft_shift_fractal(data);
	if (ft_strncmp(data->draw.fractal_type, "m", 1) == 0)
		draw_mandelbrot(data);
	else if (ft_strncmp(data->draw.fractal_type, "j", 1) == 0)
		draw_julia(data);
	else if (ft_strncmp(data->draw.fractal_type, "b", 1) == 0)
		draw_burningship(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

int	handle_mousepress(int button, int x, int y, t_data *data)
{
	data->draw.x += (x - WIDTH / 2) * data->draw.zoom / WIDTH;
	data->draw.y += (y - HEIGHT / 2) * data->draw.zoom / HEIGHT;
	if (button == 4 || button == 5)
	{
		if (button == 4)
			data->draw.zoom /= 1.1;
		else if (button == 5)
			data->draw.zoom *= 1.1;
		data->draw.x -= (x - WIDTH / 2) * data->draw.zoom / WIDTH;
		data->draw.y -= (y - HEIGHT / 2) * data->draw.zoom / HEIGHT;
		if (ft_strncmp(data->draw.fractal_type, "m", 1) == 0)
			draw_mandelbrot(data);
		else if (ft_strncmp(data->draw.fractal_type, "j", 1) == 0)
			draw_julia(data);
		else if (ft_strncmp(data->draw.fractal_type, "b", 1) == 0)
			draw_burningship(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	return (0);
}

void	handle_events(t_data *data)
{
	mlx_key_hook(data->win, &handle_keypress, data);
	mlx_hook(data->win, 17, 1L << 2, close_win, data);
	mlx_mouse_hook(data->win, &handle_mousepress, data);
	mlx_loop(data->mlx);
}

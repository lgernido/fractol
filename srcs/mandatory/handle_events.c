/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:23:13 by lgernido          #+#    #+#             */
/*   Updated: 2024/01/07 13:23:35 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	return (0);
}

int	handle_mousepress(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4 || button == 5)
	{
		if (button == 4)
			data->draw.zoom /= 1.1;
		else if (button == 5)
			data->draw.zoom *= 1.1;
		if (ft_strncmp(data->draw.fractal_type, "m", 1) == 0)
			draw_mandelbrot(data);
		else if (ft_strncmp(data->draw.fractal_type, "j", 1) == 0)
			draw_julia(data);
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

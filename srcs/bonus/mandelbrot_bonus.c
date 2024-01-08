/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:12:53 by lgernido          #+#    #+#             */
/*   Updated: 2024/01/07 13:23:06 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	compute_mandelbrot(t_data *data, double x, double y)
{
	int			n;
	uint32_t	color;

	data->draw.cx = data->draw.x + (x - WIDTH / 2) * data->draw.zoom / WIDTH;
	data->draw.cy = data->draw.y + (y - HEIGHT / 2) * data->draw.zoom / HEIGHT;
	data->draw.a = 0;
	data->draw.b = 0;
	n = 0;
	while (n < MAX_ITER)
	{
		data->draw.real = (data->draw.a * data->draw.a) - (data->draw.b
				* data->draw.b);
		data->draw.imaginary = 2 * data->draw.a * data->draw.b;
		data->draw.a = data->draw.real + data->draw.cx;
		data->draw.b = data->draw.imaginary + data->draw.cy;
		n++;
		if (data->draw.a * data->draw.a + data->draw.b * data->draw.b > 4)
			break ;
	}
	color = find_color(n, data);
	my_mlx_pixel_put(&data->img, x, y, color);
}

void	draw_mandelbrot(t_data *data)
{
	double	x;
	double	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			compute_mandelbrot(data, x, y);
			x++;
		}
		y++;
	}
}

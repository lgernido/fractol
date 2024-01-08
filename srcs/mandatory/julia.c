/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:03:56 by lgernido          #+#    #+#             */
/*   Updated: 2024/01/08 10:32:48 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute_julia(t_data *data, double x, double y)
{
	int			n;
	double		r;
	double		i;
	uint32_t	color;

	data->draw.a = data->draw.x + (x - WIDTH / 2) * data->draw.zoom / WIDTH;
	data->draw.b = data->draw.y + (y - HEIGHT / 2) * data->draw.zoom / HEIGHT;
	n = 0;
	while (n < MAX_ITER)
	{
		r = (data->draw.a * data->draw.a) - (data->draw.b * data->draw.b);
		i = 2 * data->draw.a * data->draw.b;
		data->draw.a = data->draw.real + r;
		data->draw.b = data->draw.imaginary + i;
		n++;
		if (data->draw.a * data->draw.a + data->draw.b * data->draw.b > 2)
			break ;
	}
	color = find_color(n, data);
	my_mlx_pixel_put(&data->img, x, y, color);
}

void	draw_julia(t_data *data)
{
	double	x;
	double	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			compute_julia(data, x, y);
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_color_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:39:40 by lgernido          #+#    #+#             */
/*   Updated: 2024/01/08 10:43:41 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_shift_color(t_data *data)
{
	if (ft_strncmp(data->draw.palette, "rainbow", 7) == 0)
		data->draw.palette = "red";
	else if (ft_strncmp(data->draw.palette, "red", 3) == 0)
		data->draw.palette = "blue";
	else if (ft_strncmp(data->draw.palette, "blue", 4) == 0)
		data->draw.palette = "grey";
	else if (ft_strncmp(data->draw.palette, "grey", 4) == 0)
		data->draw.palette = "rainbow";
}

uint32_t	find_more_color(int n, t_data *data)
{
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;

	red = 0x00;
	green = 0x00;
	blue = 0x00;
	if (ft_strncmp(data->draw.palette, "blue", 4) == 0)
	{
		red = 0x00;
		green = 0x00;
		blue = 0xE4 - (n * 10);
	}
	else if (ft_strncmp(data->draw.palette, "grey", 4) == 0)
	{
		red = 0x80 + (n * 10);
		green = 0x80 + (n * 10);
		blue = 0x80 + (n * 10);
	}
	else
		display_help();
	return (red << 16 | green << 8 | blue);
}

uint32_t	find_color(int n, t_data *data)
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;

	red = 0x00;
	green = 0x00;
	blue = 0x00;
	if (n == MAX_ITER)
		return (0x00000000);
	else if (ft_strncmp(data->draw.palette, "rainbow", 7) == 0)
	{
		red = 0x0D + (n * 5);
		green = 0x21 + (n * 8);
		blue = 0x90 + (n * 10);
	}
	else if (ft_strncmp(data->draw.palette, "red", 3) == 0)
	{
		red = 0xE7 - (n * 10);
		green = 0x00;
		blue = 0x00;
	}
	else
		return (find_more_color(n, data));
	return ((red << 16) | (green << 8) | blue);
}

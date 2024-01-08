/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:39:40 by lgernido          #+#    #+#             */
/*   Updated: 2024/01/08 10:21:18 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		display_help();
	return ((red << 16) | (green << 8) | blue);
}

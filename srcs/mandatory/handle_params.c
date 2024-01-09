/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:12:53 by lgernido          #+#    #+#             */
/*   Updated: 2024/01/09 15:22:23 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_help(t_data *data)
{
	ft_printf("Invalid parameters\n\n");
	ft_printf("Syntax: ./fractol ");
	ft_printf("[fractal type] [color] (julia real) (julia imaginary)\n\n");
	ft_printf("Fractal types : Mandelbrot(m), Julia(j), Burning(b)\n");
	ft_printf("Colors : red, rainbow\n\n");
	ft_printf("For Julia set, real and imaginary are mandatory\n");
	ft_printf("Real and imaginary must be between -2 and 2\n\n");
	ft_printf("Exemple: ./fractol j red -1 0\n");
	close_win(data);
	exit(1);
}

void	set_fractal_type(t_data *data, char *fractal_type, int argc)
{
	size_t	max_len;

	max_len = ft_strlen(fractal_type);
	if (ft_strncmp(fractal_type, "Mandelbrot", max_len) == 0
		|| ft_strncmp(fractal_type, "m", max_len) == 0)
	{
		draw_mandelbrot(data);
		data->draw.fractal_type = "m";
	}
	else if ((ft_strncmp(fractal_type, "Julia", max_len) == 0
			|| ft_strncmp(fractal_type, "j", max_len) == 0) && argc == 5)
	{
		draw_julia(data);
		data->draw.fractal_type = "j";
	}
	else
		display_help(data);
}

void	choose_fractal(int argc, char **argv, t_data *data)
{
	char	*fractal_type;

	fractal_type = argv[1];
	set_fractal_type(data, fractal_type, argc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:46:32 by lgernido          #+#    #+#             */
/*   Updated: 2024/01/10 10:04:12 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	display_help(void)
{
	ft_printf("Invalid parameters\n\n");
	ft_printf("Syntax : ./fractol ");
	ft_printf("[fractal type] [color] (julia real) (julia imaginary)\n\n");
	ft_printf("Fractal types : Mandelbrot(m), Julia(j), Burning(b)\n");
	ft_printf("Click on 'f' to go from mandelbrot to burning ship fractal\n\n");
	ft_printf("Colors : blue, grey, red, rainbow\n");
	ft_printf("Click on 'c' to change the color of the fractal\n\n");
	ft_printf("For Julia set, real and imaginary are mandatory\n");
	ft_printf("Real and imaginary must be between -2 and 2\n\n");
	ft_printf("Exemple: ./fractol j red -1 0\n");
	exit(1);
}

void	check_params(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 3 || argc > 5)
		display_help();
	if (argc > 3)
	{
		if (argc > 4 && (ft_atod(argv[4]) < -2 || ft_atod(argv[4]) > 2))
			display_help();
		else if (ft_atod(argv[3]) < -2 || ft_atod(argv[3]) > 2)
			display_help();
	}
	if ((ft_strncmp(argv[1], "Mandelbrot", 11) == 0 && argc > 3)
		|| (ft_strncmp(argv[1], "m", 1) == 0 && argc > 3))
		display_help();
	if ((ft_strncmp(argv[1], "Burning", 7) == 0 && argc > 3)
		|| (ft_strncmp(argv[1], "b", 1) == 0 && argc > 3))
		display_help();
	while (argv[2] != NULL && argv[2][i] != '\0')
	{
		if (ft_isalpha(argv[2][i]) == 0)
			display_help();
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_params(argc, argv);
	struct_init(&data, argc, argv);
	data = ft_init(&data);
	choose_fractal(argc, argv, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	handle_events(&data);
	return (0);
}

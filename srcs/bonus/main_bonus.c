/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:46:32 by lgernido          #+#    #+#             */
/*   Updated: 2024/01/08 13:03:29 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	check_params(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 3)
		display_help();
	if (argc > 3)
	{
		if (ft_atod(argv[3]) < -2 || ft_atod(argv[3]) > 2)
			display_help();
		else if (ft_atod(argv[4]) < -2 || ft_atod(argv[2]) > 2)
			display_help();
	}
	if (((ft_strncmp(argv[1], "Mandelbrot", 11) == 0) && argc > 3)
		|| ((ft_strncmp(argv[1], "m", 1) == 0) && argc > 3))
		display_help();
	if (((ft_strncmp(argv[1], "Burning", 7) == 0) && argc > 3)
		|| ((ft_strncmp(argv[1], "b", 1) == 0) && argc > 3))
		display_help();
	while (argv[2])
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
	data = ft_init(&data, argc, argv);
	choose_fractal(argc, argv, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	handle_events(&data);
	return (0);
}

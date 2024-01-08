/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:46:32 by lgernido          #+#    #+#             */
/*   Updated: 2024/01/08 10:35:36 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	check_params(int argc, char **argv)
{
	if (argc < 3)
		display_help();
	if (argc > 3)
	{
		if (ft_atod(argv[3]) < -2 || ft_atod(argv[3]) > 2)
			display_help();
		else if (ft_atod(argv[4]) < -2 || ft_atod(argv[2]) > 2)
			display_help();
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

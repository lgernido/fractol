/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:46:32 by lgernido          #+#    #+#             */
/*   Updated: 2024/01/09 15:13:40 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	check_params(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	if (argc < 3 || argc > 5)
		display_help(data);
	if (argc > 3)
	{
		if (argc > 4 && (ft_atod(argv[4]) < -2 || ft_atod(argv[4]) > 2))
			display_help(data);
		else if (ft_atod(argv[3]) < -2 || ft_atod(argv[3]) > 2)
			display_help(data);
	}
	if ((ft_strncmp(argv[1], "Mandelbrot", 11) == 0 && argc > 3)
		|| (ft_strncmp(argv[1], "m", 1) == 0 && argc > 3))
		display_help(data);
	if ((ft_strncmp(argv[1], "Burning", 7) == 0 && argc > 3)
		|| (ft_strncmp(argv[1], "b", 1) == 0 && argc > 3))
		display_help(data);
	while (argv[2] != NULL && argv[2][i] != '\0')
	{
		if (ft_isalpha(argv[2][i]) == 0)
			display_help(data);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_params(argc, argv, &data);
	struct_init(&data, argc, argv);
	data = ft_init(&data);
	choose_fractal(argc, argv, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	handle_events(&data);
	return (0);
}

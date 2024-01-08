/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:53:30 by lgernido          #+#    #+#             */
/*   Updated: 2024/01/08 10:02:55 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	handle_error(void)
{
	ft_printf("Erreur avec la MLX");
	exit(1);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	struct_init(t_data *data, int argc, char **argv)
{
	data->draw.x = 0;
	data->draw.y = 0;
	data->draw.fractal_type = argv[1];
	data->draw.x_mouse = 0;
	data->draw.y_mouse = 0;
	data->draw.zoom = 4;
	data->draw.palette = argv[2];
	if (argc > 3)
	{
		data->draw.real = ft_atod(argv[3]);
		data->draw.imaginary = ft_atod(argv[4]);
	}
}

t_data	ft_init(t_data *data, int argc, char **argv)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		handle_error();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract'ol");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		handle_error();
	}
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	struct_init(data, argc, argv);
	return (*data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:16:26 by lgernido          #+#    #+#             */
/*   Updated: 2024/01/09 14:01:58 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isspace(int c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

static double	parse_int(char *nptr, int *index)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(nptr[*index]))
	{
		result = result * 10.0 + (nptr[*index] - '0');
		(*index)++;
	}
	return (result);
}

static double	parse_decimal(char *nptr, int *index)
{
	double	result;
	double	decimal;

	result = 0.0;
	decimal = 0.1;
	(*index)++;
	while (ft_isdigit(nptr[*index]))
	{
		result += (nptr[*index] - '0') * decimal;
		decimal *= 0.1;
		(*index)++;
	}
	return (result);
}

double	ft_atod(char *nptr)
{
	double	nb;
	double	sign;
	int		i;

	nb = 0.0;
	sign = 1.0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1.0;
		i++;
	}
	nb = parse_int(nptr, &i);
	if (nptr[i] == '.')
		nb += parse_decimal(nptr, &i);
	return (nb * sign);
}

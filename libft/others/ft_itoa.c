/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:06:41 by lgernido          #+#    #+#             */
/*   Updated: 2023/11/14 09:07:28 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_strsize(int n)
{
	int	size;
	int	nb;

	size = 1;
	nb = n;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		size++;
		n *= -1;
	}
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;
	int		size;

	nb = n;
	i = 0;
	size = ft_strsize(n);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
		nb = -nb;
	while (i < size)
	{
		str[size - i - 1] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/*int	main(void)
{
	int		num1;
	int		num2;
	int		num3;
	int		num4;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	num1 = -2147483648;
	num2 = -456;
	num3 = 0;
	num4 = 123;
	str1 = ft_itoa(num1);
	str2 = ft_itoa(num2);
	str3 = ft_itoa(num3);
	str4 = ft_itoa(nun4);
	printf("Integer: %d, String: %s\n", num1, str1);
	printf("Integer: %d, String: %s\n", num2, str2);
	printf("Integer: %d, String: %s\n", num3, str3);
	printf("Integer: %d, String: %s\n", num4, str4);
	free(str1);
	free(str2);
	free(str3);
	free(str4);
	return (0);
}*/

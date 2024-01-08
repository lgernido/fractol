/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:19:40 by lgernido          #+#    #+#             */
/*   Updated: 2023/11/13 14:11:43 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[j] != 0)
		res[i++] = s1[j++];
	j = 0;
	while (s2[j] != 0)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

/*int	main(int argc, char **argv)
{
	if (argc > 1)
		printf("%s\n", ft_strjoin(argv[1], argv[2]));
	return (0);
}*/
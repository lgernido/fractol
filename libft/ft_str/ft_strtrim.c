/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:45:17 by lgernido          #+#    #+#             */
/*   Updated: 2023/11/16 14:52:45 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (ft_findset(s1[start], set) && s1[start])
		start++;
	while (end > start && ft_findset(s1[end - 1], set))
		end--;
	res = malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}

/*#include <stdio.h>

int	main(void)
{
	// Test cases
	char str1[] = " xx  Hello, World!   x";
	char str2[] = "   \t \n  Trim Me! \t \n  ";
	char str3[] = "NoTrimsHere";
	char str4[] = " \t \n \t ";

	// Test ft_strtrim
	char *trimmed_str1 = ft_strtrim(str1, "x");
	char *trimmed_str2 = ft_strtrim(str2, " \t\n");
	char *trimmed_str3 = ft_strtrim(str3, " \t\n");
	char *trimmed_str4 = ft_strtrim(str4, " \t\n");

	// Display the results
	printf("Original: \"%s\", Trimmed: \"%s\"\n", str1, trimmed_str1);
	printf("Original: \"%s\", Trimmed: \"%s\"\n", str2, trimmed_str2);
	printf("Original: \"%s\", Trimmed: \"%s\"\n", str3, trimmed_str3);
	printf("Original: \"%s\", Trimmed: \"%s\"\n", str4, trimmed_str4);

	// Free the allocated memory
	free(trimmed_str1);
	free(trimmed_str2);
	free(trimmed_str3);
	free(trimmed_str4);

	return (0);
}*/
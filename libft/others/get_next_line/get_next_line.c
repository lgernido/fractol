/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:13:39 by lgernido          #+#    #+#             */
/*   Updated: 2023/11/29 09:34:23 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *buffer, char *stash)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = (ft_strjoin(tmp, buffer));
		if (!stash)
			return (NULL);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*ft_clean_stash(char *line)
{
	int		i;
	char	*clean_stash;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	clean_stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!clean_stash)
		return (NULL);
	if (clean_stash[0] == '\0')
	{
		free(clean_stash);
		clean_stash = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (clean_stash);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = ft_read_line(fd, buffer, stash);
	free(buffer);
	if (!line)
		return (NULL);
	stash = ft_clean_stash(line);
	return (line);
}

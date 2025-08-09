/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helios <helios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:19:48 by bmoreira          #+#    #+#             */
/*   Updated: 2025/08/08 21:36:27 by helios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(char *buffer, int fd)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (NULL);
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(temp), NULL);
		temp[bytes] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (free(buffer), free(temp), NULL);
	}
	return (buffer);
}

char	*read_line(char *buffer, char **line)
{
	char	*left;
	size_t	line_size;

	line_size = ft_strchr(buffer, '\n');
	if (!line_size)
		line_size = ft_strlen(buffer);
	*line = ft_substr(buffer, 0, line_size);
	if (!*line)
		return (free(buffer), NULL);
	left = ft_substr(buffer, line_size, ft_strlen(buffer));
	if (!left)
		return (free(buffer), NULL);
	free(buffer);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	buffer = read_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	if (!ft_strlen(buffer))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_line(buffer, &line);
	return (line);
}

// int main(void)
// {
// 	#include <stdio.h>
// 	#include <fcntl.h>
// 	#include <unistd.h>
// 	#include <stdlib.h>
// 	int fd = open("batatas.txt", O_RDONLY);
// 	printf("main: %s", get_next_line(fd));
// 	printf("main: %s", get_next_line(fd));
// 	printf("main: %s", get_next_line(fd));
// 	printf("main: %s", get_next_line(fd));
// 	close(fd);
// }
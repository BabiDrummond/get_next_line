/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:19:48 by bmoreira          #+#    #+#             */
/*   Updated: 2025/08/07 20:06:43 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	end_of_line(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		if (s[i++] == '\n')
			return (i);
	return (0);
}

char	*get_line(char **line, char *buffer)
{
	char	*left;
	size_t	line_size;

	line_size = end_of_line(buffer);
	if (!line_size)
		line_size = ft_strlen(buffer);
	*line = ft_substr(buffer, 0, line_size);
	if (!*line)
		return (free(buffer), free(NULL), NULL);
	left = ft_substr(buffer, line_size, ft_strlen(buffer));
	if (!left)
		return (free(buffer), free(left), NULL);
	free(buffer);
	return (left);
}

char	*read_buffer(char *buffer, int fd)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp || !buffer)
		return (NULL);
	while (!end_of_line(buffer) && bytes > 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
			return (free(temp), free(buffer), NULL);
		temp[bytes] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (free(temp), free(buffer), NULL);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
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
	buffer = get_line(&line, buffer);
	return (line);
}

// int main(void)
// {
// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <stdlib.h>
// 	int fd = open("batatas.txt", O_RDONLY);
// 	printf("main: %s", get_next_line(fd));
// 	printf("main: %s", get_next_line(fd));
// 	printf("main: %s", get_next_line(fd));
// 	printf("main: %s", get_next_line(fd));
// 	close(fd);
// }
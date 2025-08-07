/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:19:48 by bmoreira          #+#    #+#             */
/*   Updated: 2025/08/06 21:30:51 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	size_t	len;

	if (size && nmemb > (size_t) -1 / size)
		return (NULL);
	len = nmemb * size;
	arr = malloc(len);
	if (!arr)
		return (NULL);
	while (len--)
		arr[len] = '\0';
	return (arr);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s)
{
	char	*new_s;
	char	*temp;

	new_s = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	temp = new_s;
	while (*s)
		*new_s++ = *s++;
	return (temp);
}

int	end_of_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		if (s[i++] == '\n')
			return (i);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	i = 0;
	j = 0;
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	//printf("strjoin: %s\n", new);
	free(s1);
	free(s2);
	return (new);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*temp;
	size_t	s_len;

	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = ft_calloc(len + 1, sizeof(char));
	temp = substr;
	if (!substr)
		return (NULL);
	while (len--)
		*substr++ = s[start++];
	//printf("substr: %s\n", temp);
	return (temp);
}

// char	*get_line(char *buffer, size_t buffer_size, size_t line_size)
// {
// 	char	*left;
// 	char	*line;
// 	left = ft_calloc(buffer_size - line_size + 1, sizeof(char));
// 	line = ft_calloc(line_size + 1, sizeof(char));
// 	if (!left || !line)
// 		return (NULL);
// 	left = ft_substr(buffer, line_size, buffer_size - line_size);
// 	line = ft_substr(buffer, 0, line_size);
// 	free(buffer);
// 	buffer = ft_strdup(left);
// 	free(left);
// 	return (line);
// }
char	*get_line(char *buffer, size_t line_size)
{
	char	*line;

	line = ft_calloc(line_size + 1, sizeof(char));
	if (!line)
		return (NULL);
	if (!line_size)
		line_size = ft_strlen(buffer);
	line = ft_substr(buffer, 0, line_size);
	//printf("line: %s\n", line);
	return (line);
}

char	*get_left(char *buffer, size_t line_size)
{
	char	*left;
	size_t	left_size;

	left_size = ft_strlen(buffer) - line_size;
	left = ft_calloc(left_size + 1, sizeof(char));
	if (!left)
		return (NULL);
	left = ft_substr(buffer, line_size, left_size);
	free(buffer);
	//printf("left: %s\n", left);
	return (left);
}

// quando ler? 1- buffer vazio. 2- buffer tem conteúdo mas não tem \n.
// quando parar de ler? 1. buffer tem conteúdo e tem \n. 2. buffer tem conteúdo e não tem \n, mas tem \0.
// caso 1: buffer vazio: ler para buffer normalmente
// caso 2: buffer tem conteudo: checar se tem \n. se nao, checar se tem \0.
char	*read_buffer(char *buffer, int fd)
{
	char	*temp;

	if (!buffer)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (buffer == NULL || read(fd, buffer, BUFFER_SIZE) < 1)
			return (NULL);
	}
	while (!end_of_line(buffer))
	{
		temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (temp == NULL || read(fd, temp, BUFFER_SIZE) < 1)
			break;
		buffer = ft_strjoin(buffer, temp);
	}
	return (buffer);
}

// char	*read_buffer(int fd)
// {
// 	char	*buffer;
// 	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	if (!buffer)
// 		return (NULL);
// 	read(fd, buffer, BUFFER_SIZE);
// 	return (buffer);
// }
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	size_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	n = end_of_line(buffer);
	line = get_line(buffer, n);
	buffer = get_left(buffer, n);
	if (!n || !buffer)
		free(buffer);
	if (!line || !*line)
		return (free(line), NULL);
	return (line);
}

// int main(void)
// {
// 	int fd = open("batatas.txt", O_RDONLY);
// 	printf("main: %s", get_next_line(fd));
// 	printf("main: %s", get_next_line(fd));
// 	printf("main: %s", get_next_line(fd));
// 	printf("main: %s", get_next_line(fd));
// 	close(fd);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:19:48 by bmoreira          #+#    #+#             */
/*   Updated: 2025/08/05 21:25:53 by bmoreira         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
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

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		if (s[i++] == c)
			return (--i);
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	char	*temp;

	new_str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	temp = new_str;
	while (*s1)
		*new_str++ = *s1++;
	while (*s2)
		*new_str++ = *s2++;
	free((char *)s1);
	free((char *)s2);
	return (temp);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	line = ft_substr(buffer, 0, line_size);
	return (line);
}

char	*get_left(char *buffer, size_t line_size)
{
	char	*left;
	
	left = ft_calloc(BUFFER_SIZE - line_size + 1, sizeof(char));
	if (!left)
		return (NULL);
	left = ft_substr(buffer, line_size, BUFFER_SIZE - line_size);
	free(buffer);
	return (left);
}

char	*read_buffer(char *buffer, int fd)
{
	char	*temp;
	
	if (!buffer)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (buffer == NULL)
			return (NULL);
		read(fd, buffer, BUFFER_SIZE);
	}
	else
	{
		temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (temp == NULL)
			return (NULL);
		read(fd, temp, BUFFER_SIZE);
		return (ft_strjoin(buffer, temp));
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	size_t		n;
	
	printf("1?");
	while (!ft_strchr(buffer, '\n') && printf("2"))
		buffer = read_buffer(buffer, fd);
	n = ft_strchr(buffer, '\n');
	printf("3");
	line = get_line(buffer, n);
	printf("4");
	if (buffer[n + 1] == '\0' && printf("5"))
		free(buffer);
	else
		buffer = get_left(buffer, n);
	printf("6");
	return (line);
}

int main(void)
{
	printf("while?");
	int fd = open("batatas.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// close(fd);
}
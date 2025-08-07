/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftjoin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:26:25 by bmoreira          #+#    #+#             */
/*   Updated: 2025/08/06 21:29:00 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <unistd.h>
// #include <stdio.h>

// size_t	ft_strlen(char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	char	*arr;
// 	size_t	len;

// 	if (size && nmemb > (size_t) -1 / size)
// 		return (NULL);
// 	len = nmemb * size;
// 	arr = malloc(len);
// 	if (!arr)
// 		return (NULL);
// 	while (len--)
// 		arr[len] = '\0';
// 	return (arr);
// }
// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*new;
// 	int		i;
// 	int		j;

// 	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
// 	i = -1;
// 	j = -1;
// 	if (!new)
// 		return (NULL);
// 	while (s1[i++])
// 		new[i] = s1[i];
// 	while (s2[j++])
// 		new[i + j] = s2[j];
// 	printf("strjoin: %s\n", new);
// 	return (new);
// }

// int main(void)
// {
//     char *hello = "hello\n";
//     char *bye = "bye";

//     printf("%s", ft_strjoin(hello, bye));
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:21:17 by psitkin           #+#    #+#             */
/*   Updated: 2024/01/04 22:11:28 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char	*ft_lstrdup(const char *src, int l); 
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

char	*get_next_line(int fd)
{
	int		bytes_read;
	char	*cup_buffer;
	char	*output;
	int		i;

	bytes_read = 1;
	cup_buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (cup_buffer == NULL)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		cup_buffer[BUFFER_SIZE] = '\0';
		i = 0;
		while (cup_buffer[i] != '\0')
		{
			if (cup_buffer[i++] == '\n')
			{
				output = ft_strjoin(output, cup_buffer);
				return (output);
			}
		}
		if (output == 0)
			output = ft_lstrdup(cup_buffer, BUFFER_SIZE + 1);
		else 
			output = ft_strjoin(output, cup_buffer);
	}
	return (output);
}

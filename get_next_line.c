/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:21:17 by psitkin           #+#    #+#             */
/*   Updated: 2024/01/13 00:22:59 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"


char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	*cup_buffer;
	char		*output;
	int			i;

	cup_buffer = NULL;
	
	cup_buffer = read_from_file(fd, cup_buffer);
	
	if (cup_buffer == NULL)
		return (ft_free(&cup_buffer));
		
// 	while (bytes_read > 0)
// 	{
// 		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
// 		if (bytes_read < 0)
// 			return (NULL);
// 		cup_buffer[BUFFER_SIZE] = '\0';
// 		i = 0;
// 		while (cup_buffer[i] != '\0')
// 		{
// 			if (cup_buffer[i++] == '\n')
// 			{
// 				output = ft_strjoin(output, cup_buffer);
// 				return (output);
// 			}			
// 		}
// 		output = ft_strjoin(output, cup_buffer);
// 	}
// 	return (output);
// }

char	*read_from_file(int fd, char *buffer)
{
	char	*tmp;
	int		bytes;
	
	buffer = check_string(buffer);
	if (!buffer)
		return (0);
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (ft_free(&cup_buffer));
	bytes = 1;
	while (!ft_strchr(cup_buffer, '\n')&& bytes != 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
			return (ft_free(&tmp));
		tmp[bytes] = '\0';
		buffer = ft_strjoin(cup_buffer, tmp);
		if (!cup_buffer)
			return (ft_free(&cup_buffer));
	}
	free(tmp);
	return (buffer);
}
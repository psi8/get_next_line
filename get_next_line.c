/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:21:17 by psitkin           #+#    #+#             */
/*   Updated: 2024/01/12 21:18:44 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"


char	*get_next_line(int fd)
{
	int		bytes_read;
	char	*cup_buffer;
	char	*output;
	int		i;

	if (!output)
	{
		output = malloc(1);
		output[0] = '\0';
	}
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
		output = ft_strjoin(output, cup_buffer);
	}
	return (output);
}

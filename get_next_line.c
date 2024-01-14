/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:21:17 by psitkin           #+#    #+#             */
/*   Updated: 2024/01/14 20:19:57 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*cup_buffer;
	char		*output;

	cup_buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (ft_free(&cup_buffer));
	cup_buffer = read_from_file(fd, cup_buffer);
	if (cup_buffer == NULL)
		return (ft_free(&cup_buffer));
	output = find_line(cup_buffer);
	cup_buffer = rest_of_file(cup_buffer);
	return (output);
}

char	*read_from_file(int fd, char *cup_buffer)
{
	char	*tmp;
	int		bytes;

	cup_buffer = check_string(cup_buffer);
	if (!cup_buffer)
		return (0);
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (ft_free(&cup_buffer));
	bytes = 1;
	while (!ft_strchr(cup_buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
			return (ft_free(&tmp));
		tmp[bytes] = '\0';
		cup_buffer = ft_strjoin(cup_buffer, tmp);
		if (!cup_buffer)
			return (ft_free(&cup_buffer));
	}
	free(tmp);
	return (cup_buffer);
}

char	*find_line(char *cup_buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!cup_buffer)
		return (NULL);
	while (cup_buffer[i] && cup_buffer[i] != '\n')
		i++;
	if (cup_buffer[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (cup_buffer[i] && cup_buffer[i] != '\n')
	{
		line[i] = cup_buffer[i];
		i++;
	}
	if (cup_buffer[i] == 'n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*rest_of_file(char *cup_buffer)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	if (!cup_buffer)
		return (NULL);
	while (cup_buffer[i] && cup_buffer[i] != '\n')
		i++;
	if (cup_buffer[i])
	{
		free(cup_buffer);
		return (NULL);
	}
	rest = (char *)malloc(sizeof (char) * (ft_strlen(cup_buffer) - i + 1));
	if (!rest)
		return (ft_free(&cup_buffer));
	i++;
	j = 0;
	while (cup_buffer[i])
		rest[j++] = cup_buffer[i++];
	rest[j] = '\0';
	free (cup_buffer);
	return (rest);
}
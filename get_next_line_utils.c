/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:09:38 by psitkin           #+#    #+#             */
/*   Updated: 2024/01/19 21:27:57 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*joinstr;

	s1_len = 0;
	s2_len = 0;
	joinstr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!joinstr)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	while (s1 && s1[s1_len])
	{
		joinstr[s1_len] = s1[s1_len];
		s1_len++;
	}
	while (s2 && s2[s2_len])
		joinstr[s1_len++] = s2[s2_len++];
	joinstr[s1_len] = '\0';
	free(s1);
	return (joinstr);
}

char	*check_string(char *s)
{
	if (!s)
	{
		s = (char *)malloc(sizeof(char) * 1);
		if (!s)
			return (NULL);
		*s = 0;
	}
	return (s);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)(str));
		str++;
	}
	if (*str == '\0' && (char)c == '\0')
		return ((char *)(str));
	return (NULL);
}

char	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

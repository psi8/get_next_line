/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:09:38 by psitkin           #+#    #+#             */
/*   Updated: 2024/01/12 00:31:57 by psitkin          ###   ########.fr       */
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

size_t	ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[src_len] != 0)
		return (src_len);
	return (src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*joinstr;

	s1_len = 0;
	s2_len = 0;
	joinstr = malloc(sizeof (char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!joinstr)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	while (s1 && s1[s1_len])
		joinstr[s1_len++] = s1[s1_len++];
	while (s2 && s2[s2_len])
		joinstr[s1_len++] = s2[s2_len++];
	joinstr[s1_len] = '\0';
	free(s1);
	return (joinstr);
}
// char	*ft_lstrdup(char *src, int l)
// {
// 	char	*dst;

// 	dst = malloc(l);
// 	if (!dst)
// 		return ((char *) 0);
// 	ft_strlcpy(dst, src, l);
// 	return (dst);
// }
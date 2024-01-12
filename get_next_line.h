/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psitkin <psitkin@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:51:46 by psitkin           #+#    #+#             */
/*   Updated: 2024/01/13 01:24:59 by psitkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
# endif

#include <stdlib.h>
#include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dest, char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_free(char **str);
char	*ft_strchr(const char *str, int c);
char	*check_string(char *s);
char	*read_from_file(int fd, char *cup_buffer);
char	*find_line(char *cup_buffer);




#endif
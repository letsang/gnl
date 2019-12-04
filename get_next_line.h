/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 07:01:56 by jtsang            #+#    #+#             */
/*   Updated: 2019/12/04 14:36:12 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#		ifndef GET_NEXT_LINE_H
#		define GET_NEXT_LINE_H

#		include <stdlib.h>
#		include <string.h>
#		include <unistd.h>

#define BUF_SIZE 50

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strcat(char *dst, char const *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_stock(int fd, char **stock);
char	*get_newline(char **stock);
int		get_next_line(int fd, char **line);

#		endif

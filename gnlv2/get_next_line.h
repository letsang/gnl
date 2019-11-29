/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 07:01:56 by jtsang            #+#    #+#             */
/*   Updated: 2019/11/29 17:09:37 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#		ifndef GET_NEXT_LINE_H
#		define GET_NEXT_LINE_H

#		include <stdlib.h>
#		include <string.h>
#		include <unistd.h>

#define BUF_SIZE 10

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strcat(char *dst, char const *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_stock(char **stock, int ret, char *buf);
int		is_line(char *stock, int ret);
char	*get_the_line(char **stock, int ret);
int		get_next_line(int fd, char **line);

#		endif

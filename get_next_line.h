/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 07:01:56 by jtsang            #+#    #+#             */
/*   Updated: 2019/11/28 09:32:39 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#		ifndef GET_NEXT_LINE_H
#		define GET_NEXT_LINE_H

#		include <stdlib.h>
#		include <string.h>
#		include <unistd.h>

#define BUF_SIZE 999

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

int		count_strs(char c, const char *s);
char	*ft_strdup_c(const char *src, char c);
char	**free_all(char **tab, int i);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strcat(char *dst, char const *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_stock(int fd);
char	**get_stock_split(char *stock);
int		get_next_line(int fd, char **line);

#		endif

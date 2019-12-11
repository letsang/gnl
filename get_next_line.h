/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 07:01:56 by jtsang            #+#    #+#             */
/*   Updated: 2019/12/11 18:07:21 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#		ifndef GET_NEXT_LINE_H
#		define GET_NEXT_LINE_H

#		include <fcntl.h>
#		include <sys/types.h>
#		include <sys/uio.h>
#		include <stdlib.h>
#		include <string.h>
#		include <unistd.h>

char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *s);
char	*free_join_stock(char *stock, char *buf);
char	*ft_strjoin(char *s1, char *s2);
char	*get_stock(int fd, char **stock);
char	*get_newline(char **stock);
int		get_next_line(int fd, char **line);

#		endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:36:24 by jtsang            #+#    #+#             */
/*   Updated: 2019/12/09 09:25:33 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	if (!s)
		return (NULL);
	if (!(sub = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (((size_t)start <= ft_strlen(s)) && s[start] && (i < len))
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s && *s != c)
		s++;
	if (*s == 0)
		return (0);
	return ((char *)s);
}

char	*get_stock(int fd, char **stock)
{
	char			*buf;
	int				ret;

	ret = 1;
	while (ret && !(ft_strchr(*stock, '\n')))
	{
		buf = NULL;
		if (buf == NULL && !(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (NULL);
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free(buf);
			free(*stock);
			return (NULL);
		}
		buf[ret] = '\0';
		*stock = ft_strjoin(*stock, buf);
		free(buf);
	}
	return (*stock);
}

char	*get_newline(char **stock)
{
	char			*newline;
	char			*newstock;

	newline = NULL;
	if ((newstock = ft_strchr(*stock, '\n')))
	{
		newline = ft_substr(*stock, 0, ft_strlen(*stock) - ft_strlen(newstock));
		*stock = newstock + 1;
	}
	else
	{
		newline = ft_strdup(*stock);
		*stock = NULL;
	}
	return (newline);
}

int		get_next_line(int fd, char **line)
{
	static char		*stock = NULL;

	if (fd < 0 || !line || BUFFER_SIZE == 0 ||
			(stock == NULL && !(stock = ft_strdup(""))))
		return (-1);
	if (!(stock = get_stock(fd, &stock)))
		return (-1);
	if (*stock)
	{
		if (!(*line = get_newline(&stock)))
			return (-1);
		return (stock ? 1 : 0);
	}
	else
	{
		free(*line);
		*line = ft_strdup("");
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:36:24 by jtsang            #+#    #+#             */
/*   Updated: 2019/11/29 17:12:37 by jtsang           ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	*ft_strcat(char *dst, char const *src)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (!s1 && !s2)
		return (NULL);
	if (!(join = (char *)malloc((sizeof(char)) *
				(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	join = ft_strcpy(join, s1);
	join = ft_strcat(join, s2);
	return (join);
}

char	*get_stock(char **stock, int ret, char *buf)
{
	if (*stock && ret >= 0)
	{
		buf[ret] = '\0';
		*stock = ft_strjoin(*stock, buf);
	}
	else if (!(*stock) && ret >= 0)
	{
		buf[ret] = '\0';
		*stock = ft_substr(buf, 0, ft_strlen(buf));
	}
	return (*stock);
}

int		is_line(char *stock, int ret)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (stock && stock[i])
	{
		if (stock[i] == '\n')
			count++;
		if (ret == 0 && stock[i] == '\0')
			return (1);
		i++;
	}
	if (count >=2)
		return (1);
	return (0);
}

char	*get_the_line(char **stock, int ret)
{
	size_t	i;
	char	*the_line;
	char	*tmp;

	i = 0;
	if (ret > 0)
	{
		while (stock[0][i] && stock[0][i] != '\n')
			i++;
		the_line = ft_substr(*stock, 0, i);
		tmp = ft_substr(*stock, i + 1, ft_strlen(*stock));
		*stock = tmp;
		free(tmp);
	}
	if (ret == 0)
	{
		while (stock[0][i] && stock[0][i] != '\0')
			i++;
		the_line = ft_substr(*stock, 0, i);
	}
	return (the_line);
}

int		get_next_line(int fd, char **line)
{
	static char *stock;
	static int	ret = 0;
	char		*buf;

	printf("stock : %s", stock);
	if (!(buf = (char *)malloc(sizeof(char) * BUF_SIZE + 1)))
		return (-1);
	if (stock && is_line(stock, ret))
	{
		*line = get_the_line(&stock, ret);
		if (ret > 0)
			return (1);
		else
			return (0);
	}
	else
	{
		if ((ret = read(fd, buf, BUF_SIZE)) == -1)
		{
			free(buf);
			free(stock);
			return (-1);
		}
		if (ret >= 0)
		{
			stock = get_stock(&stock, ret, buf);
			get_next_line(fd, line);
		}
	}
	return (0);
}

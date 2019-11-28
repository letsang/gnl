/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:36:24 by jtsang            #+#    #+#             */
/*   Updated: 2019/11/28 10:06:29 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_stock(int fd)
{
	int				ret;
	size_t			buffer;
	char			*buf;
	static char		*stock;

	buffer = BUF_SIZE + 1;
	if (!(buf = (char *)malloc(sizeof(char) * buffer)))
		return (NULL);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (ret == -1)
		{
			free(buf);
			free(stock);
			return (NULL);
		}
		buf[ret] = '\0';
		if (!stock)
		{
			if (!(stock = (char *)malloc(sizeof(char) * 1)))
				return (NULL);
			stock[0] = '\0';
			stock = ft_strjoin(stock, buf);
		}
		else
			stock = ft_strjoin(stock, buf);
		if (ret == 0)
		{
			buf[ft_strlen(buf)] = '\0';
			stock = ft_strjoin(stock, buf);
			free(buf);
		}
		free(buf);
		if (!(buf = (char *)malloc(sizeof(char) * (buffer))))
			return (NULL);
	}
	return (stock);
}

char		**get_stock_split(char *stock)
{
	char	**stock_split;

	stock_split = ft_split(stock, '\n');
	return (stock_split);
}

int			get_next_line(int fd, char **line)
{
	static char **stock;
	static int	i = 0;

	if (i == 0 && !stock)
	{
		stock = get_stock_split(get_stock(fd));
		*line = *(stock + i);
		i++;
		return (1);
	}
	if (i != 0 && stock[i])
	{
		*line = *(stock + i);
		i++;
		if (i > 0 && stock + i)
			free(*(stock + i - 1));
		return (1);
	}
	if (i != 0 && stock[i] == NULL)
		return (0);
	else
		return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:36:24 by jtsang            #+#    #+#             */
/*   Updated: 2019/12/11 18:04:50 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_stock(int fd, char **stock)
{
	char			*buf;
	char			*tmp;
	int				ret;

	ret = 1;
	while (ret && !(ft_strchr(*stock, '\n')))
	{
		buf = NULL;
		if (buf == NULL &&
				!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (NULL);
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free(buf);
			free(*stock);
			return (NULL);
		}
		buf[ret] = '\0';
		tmp = *stock;
		*stock = ft_strjoin(tmp, buf);
		free(tmp);
		free(buf);
	}
	return (*stock);
}

char	*get_newline(char **stock)
{
	char			*newline;
	char			*newstock;
	char			*tmp;

	newline = NULL;
	if ((newstock = ft_strchr(*stock, '\n')))
	{
		newline = ft_substr(*stock, 0, ft_strlen(*stock) - ft_strlen(newstock));
		tmp = *stock;
		*stock = ft_strdup(newstock + 1);
		free(tmp);
	}
	else
	{
		newline = ft_strdup(*stock);
		free(*stock);
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
	if (stock && !(*line = get_newline(&stock)))
		return (-1);
	return (stock ? 1 : 0);
}

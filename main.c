/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:54:32 by jtsang            #+#    #+#             */
/*   Updated: 2019/11/26 17:51:36 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <string.h>

#include <stdio.h>

int	get_next_line(int fd, char **line);

static void ft_putstr(char *s)
{
	int  i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main()
{
	int fd;
	static char **line;

	line = NULL;
	fd = open("pokemon", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	while (get_next_line(fd, line))
	{
		get_next_line(fd, line);
//		ft_putstr(*line);
	}
	if (close(fd) == -1)
	{
		ft_putstr("close() error");
		return (1);
	}
	return (0);
}

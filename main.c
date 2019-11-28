/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:54:32 by jtsang            #+#    #+#             */
/*   Updated: 2019/11/28 09:38:35 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	(void)ac;
	int fd;
	static char *line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("%s", "open() error");
		return (1);
	}
		
	while (get_next_line(fd, &line))
	{
		printf("%s", line);
		printf("%c", '\n');
	}
	
	if (close(fd) == -1)
	{
		printf("%s", "close() error");
		return (1);
	}
	return (0);
}

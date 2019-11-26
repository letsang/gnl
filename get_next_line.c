/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:36:24 by jtsang            #+#    #+#             */
/*   Updated: 2019/11/26 17:51:03 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 999

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

static int	count_strs(char c, const char *s)
{
	int		count;
	int		interupt;
	int		i;

	count = 0;
	interupt = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			interupt = 0;
		else if (interupt == 0)
		{
			interupt = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*ft_strdup_c(const char *src, char c)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i] != '\0' && src[i] != c)
		i++;
	if (!(dup = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	**free_all(char **tab, int i)
{
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (count_strs(c, s) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((i == 0 && s[0] != c)
			|| (s[i] != c && s[i - 1] == c))
		{
			if (!(tab[j] = ft_strdup_c(s + i, c)))
				return (free_all(tab, j));
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	i = 0;
	while (s1[i])
		i++;
	if (!(dup = (char*)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

void ft_putstr(char *s)
{
	int  i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
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

char		*ft_strjoin(char const *s1, char const *s2)
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

char		*get_stock(int fd)
{
	int				ret;
	size_t			buffer;
	char			*buf;
	static char		*stock;

	buffer = BUF_SIZE + 1;
	if (!(buf = (char *)malloc(sizeof(char) * buffer)))
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (ret == -1)
		{
			free(buf);
			free(stock);
			return (0);
		}
		buf[ret] = '\0';
		if (!stock)
		{
			if (!(stock = (char *)malloc(sizeof(char) * 1)))
				return (0);
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
			return (0);
	}
	return (stock);
}

char		**get_stock_split(char *stock)
{
	char	**stock_split;

	stock_split = ft_split(stock, '\n');
	return (stock_split);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			get_next_line(int fd, char **line)
{
	static char **stock;
	static int	i = 0;

	if (i != 0 && !stock)
		return (0);
	else
	{
		if (!stock && i == 0)
			stock = get_stock_split(get_stock(fd));
		line = stock + i;
		free(stock[i]);
		i++;
		ft_putstr(*line);
		ft_putchar('\n');
		return (1);
	}
}	

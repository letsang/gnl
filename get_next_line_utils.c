/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:48:05 by jtsang            #+#    #+#             */
/*   Updated: 2019/12/11 18:04:29 by jtsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

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
		return (NULL);
	return ((char *)s);
}

char	*ft_strdup(char *s1)
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
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	if (!(join = (char*)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while ((s1)[i])
	{
		join[j] = (s1)[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		join[j] = s2[i];
		j++;
		i++;
	}
	join[j] = '\0';
	return (join);
}

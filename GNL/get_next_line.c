/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:37:56 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/30 17:23:34 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	loopread(char **ptr, char *buff, char	**str, int *l)
{
	int		i;
	char	dest[15000];
	char	*s;

	s = NULL;
	buff[*l] = 0;
	i = -1;
	*str = ft_strjoin(*str, buff);
	if (ft_strchr(*str, '\n') != 0)
	{
		s = ft_strdup(*str);
		*ptr = ft_strchr(ft_strcpy(dest, *str), '\n');
		while (s[++i])
		{
			if (s[i] == '\n')
			{
				free(*str);
				*str = ft_substr(s, 0, i + 1);
				free(s);
				return (1);
			}
		}
		free(s);
	}
	return (0);
}

char	*norm1(char **ptr, char **str, int fd)
{
	int		l;
	char	*buff;

	buff = NULL;
	l = 1;
	free(*str);
	*str = ft_strdup(*ptr);
	while (l != 0)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE);
		l = read(fd, buff, BUFFER_SIZE);
		if (l > 0 && loopread(&*ptr, buff, &*str, &l) == 1)
			return (*str);
		else if ((l == 0 && (ft_strcmp(*ptr, "") == 0
					&& ft_strcmp(*str, "") == 0)) || l == -1)
		{
			free(*str);
			free(buff);
			return (NULL);
		}
		else if (l == 0)
			*ptr = NULL;
	}
	free(buff);
	return (*str);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	int			i;
	char		*str;
	int			l;

	l = 1;
	str = ft_strdup("");
	i = 0;
	if (!ptr)
		ptr = "";
	if (ft_strchr(ptr, '\n'))
	{
		while (ptr[i])
		{
			if (ptr[i] == '\n')
			{
				free(str);
				str = ft_substr(ptr, 0, i + 1);
				ptr = ft_strchr(ptr, '\n');
				return (str);
			}
			i++;
		}
	}
	return (norm1(&ptr, &str, fd));
}

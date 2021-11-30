/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:17:24 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/30 17:24:29 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char	*str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;
	int		b;

	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	b = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[b])
		str[i++] = s2[b++];
	free(s1);
	free(s2);
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		str = malloc(sizeof(char) * ft_strlen(s));
	else
		str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i + 1]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i + 1]);
	return (0);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!src[i])
	{
		*dst = '\0';
		return (dst);
	}
	while (src[i])
	{
		dst[i] = src[i];
		i++;
		dst[i] = '\0';
	}
	return (dst);
}

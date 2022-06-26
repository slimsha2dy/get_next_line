/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:57:10 by hwichoi           #+#    #+#             */
/*   Updated: 2022/06/26 18:04:00 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	int		size;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	buf = (char *)malloc(sizeof(char) * size);
	if (buf == 0)
		return (0);
	i = 0;
	while (*s1 && i < size)
	{
		buf[i++] = *s1;
		s1++;
	}
	while (*s2 && i < size)
	{
		buf[i++] = *s2;
		s2++;
	}
	buf[i] = 0;
	return (buf);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*ret;

	len = ft_strlen((char *)str);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

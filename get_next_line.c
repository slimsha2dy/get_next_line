/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:23:47 by hwichoi           #+#    #+#             */
/*   Updated: 2022/06/26 20:05:21 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_all(char **to_free)
{
	while (*to_free != 0)
	{
		free(*to_free);
		*to_free = 0;
		to_free++;
	}
	return (0);
}

int	is_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == '\n')
			return (i);
	}
	return (-1);
}

char	*line_ret(char **str, int i)
{
	char	*ret;
	char	*buf;
	int		cnt;

	ret = (char *)malloc(sizeof(char) * i + 1);
	if (ret == 0)
	{
		free_all(str);
		return (0);
	}
	cnt = -1;
	while (++cnt < i)
		ret[cnt] = *str[cnt];
	ret[cnt] = 0;
	buf = ft_strdup(str[i + 1]);
	if (buf == 0)
	{
		free_all(str);
		return (0);
	}
	*str = buf;
	return (ret);
}

char	*ret_left(char **str)
{
	char	*ret;

	if (*str == 0)
		return (ft_strdup(""));
	if (is_nl(*str) > -1)
		ret = line_ret(str, is_nl(*str));
	else
		ret = ft_strdup(*str);
	if (ret == 0)
		free_all(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup[OPEN_MAX];
	int			readsize;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 0)
		return (0);
	readsize = read(fd, buf, BUFFER_SIZE);
	while (readsize > 0)
	{
		buf[readsize] = 0;
		backup[fd] = ft_strjoin(backup[fd], buf);
		if (is_nl(backup[fd]) > -1)
			return (line_ret(&backup[fd], is_nl(backup[fd])));
		readsize = read(fd, buf, BUFFER_SIZE);
	}
	if (readsize < 0)
	{
		free_all(backup);
		return (0);
	}
	return (ret_left(&backup[fd]));
}

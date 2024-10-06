/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:34:48 by zzetoun           #+#    #+#             */
/*   Updated: 2024/07/27 21:34:55 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char *buff[], int fd)
{
	free(buff[fd]);
	buff[fd] = NULL;
}

void	ft_remain(char *buff[], int fd)
{
	char	*remain;
	int		idx;
	int		jdx;

	idx = 0;
	while (buff[fd][idx] && buff[fd][idx] != '\n')
		idx++;
	if (!buff[fd][idx])
	{
		ft_free(buff, fd);
		return ;
	}
	remain = malloc (ft_strlen(buff[fd]) + 1 - idx++);
	if (!remain)
	{
		ft_free(buff, fd);
		return ;
	}
	jdx = 0;
	while (buff[fd][idx])
		remain[jdx++] = buff[fd][idx++];
	remain[jdx] = '\0';
	free(buff[fd]);
	buff[fd] = remain;
}

char	*ft_line(char *buff)
{
	char	*line;
	int		len;

	if (!ft_strlen(buff))
		return (NULL);
	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	if (buff[len] == '\n')
		line = malloc(len + 2);
	else
		line = malloc(len + 1);
	if (!line)
		return (NULL);
	if (buff[len] == '\n')
		line[len + 1] = '\0';
	else
		line[len] = '\0';
	while (len >= 0)
	{
		line[len] = buff[len];
		len--;
	}
	return (line);
}

void	ft_read_file(char *buff[], int fd)
{
	char	*line;
	int		len;

	line = malloc(BUFFER_SIZE + 1);
	if (!line)
	{
		ft_free(buff, fd);
		return ;
	}
	len = 1;
	while (!ft_strchr(buff[fd]) && len != 0)
	{
		len = read(fd, line, BUFFER_SIZE);
		if (len < 0)
		{
			free(line);
			ft_free(buff, fd);
			return ;
		}
		line[len] = '\0';
		buff[fd] = ft_strjoin(buff[fd], line);
	}
	free(line);
}

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FD];
	char		*print;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	ft_read_file(buff, fd);
	if (!buff[fd])
		return (NULL);
	print = ft_line(buff[fd]);
	if (!print)
		return (free(buff[fd]), buff[fd] = NULL, NULL);
	ft_remain(buff, fd);
	return (print);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:39:14 by zzetoun           #+#    #+#             */
/*   Updated: 2024/07/23 12:39:15 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strchr(char *str)
{
	int	idx;

	idx = 0;
	if (!str)
		return (0);
	while (str[idx] != '\0')
	{
		if (str[idx] == '\n')
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strjoin(char buff[], char *str)
{
	char	*join;
	int		idx;
	int		jdx;

	if (!buff)
		buff[0] = '\0';
	if (!str)
		return (NULL);
	join = malloc(ft_strlen(buff) + ft_strlen(str) + 1);
	if (!join)
		return (NULL);
	idx = -1;
	while (buff[++idx])
		join[idx] = buff[idx];
	jdx = 0;
	while (str[jdx])
		join[idx++] = str[jdx++];
	join[idx] = '\0';
	return (join);
}

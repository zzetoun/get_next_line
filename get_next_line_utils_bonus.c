/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:11:13 by zzetoun           #+#    #+#             */
/*   Updated: 2024/07/28 14:11:32 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char *buff, char *str)
{
	char	*join;
	int		idx;
	int		jdx;

	if (!buff)
	{
		buff = malloc(sizeof(char));
		if (!buff)
			return (NULL);
		buff[0] = '\0';
	}
	if (!str)
		return (NULL);
	join = malloc(ft_strlen(buff) + ft_strlen(str) + 1);
	if (!join)
		return (free(buff), buff = NULL, NULL);
	idx = -1;
	while (buff[++idx])
		join[idx] = buff[idx];
	jdx = 0;
	while (str[jdx])
		join[idx++] = str[jdx++];
	join[idx] = '\0';
	return (free(buff), buff = NULL, join);
}

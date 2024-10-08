/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:37:28 by zzetoun           #+#    #+#             */
/*   Updated: 2024/07/23 12:37:29 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_strlen(char *buff);
int		ft_strchr(char *s);
char	*get_next_line(int fd);
char	*ft_read_file(char *buff, int fd);
char	*ft_line(char *buff);
char	*ft_remain(char *buff);
char	*ft_strjoin(char *buff, char *str);

#endif
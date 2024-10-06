/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:18:51 by zzetoun           #+#    #+#             */
/*   Updated: 2024/07/28 15:18:54 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef MAX_FD
#  define MAX_FD OPEN_MAX
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_strlen(char *buff);
int		ft_strchr(char *s);
char	*get_next_line(int fd);
char	*ft_line(char *buff);
void	ft_read_file(char *buff[], int fd);
void	ft_remain(char *buff[], int fd);
char	*ft_strjoin(char *buff, char *str);

#endif

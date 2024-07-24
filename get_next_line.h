
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif


# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char    *get_next_line(int fd);
char    *ft_strlen(char *str);
char    *ft_strjoin(char *join, char *buff);

#endif
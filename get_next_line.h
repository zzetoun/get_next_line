
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif


# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int     ft_strlen(char *str);
char    *get_next_line(int fd);
char    *ft_strjoin(char *join, char *buff);
char    *ft_substr(char *buff, int start, int len);
int  ft_strlcpy(char *buff, char *tmpbuff, int size);

#endif
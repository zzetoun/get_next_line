
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int     ft_strlen(char *str);
char	*ft_strchr(char *buff, int c);
char    *ft_strjoin(char *buff, char *str);

#endif
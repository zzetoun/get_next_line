#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char    *ft_line(char *tmp, int len)
{
    char    str[len + 1];
    int     idx;

    idx = -1;
    while(++idx < len + 1)
        str[idx] = tmp[idx];
    str[idx] = '\0';
    return (str);
}

char    *get_next_line(int fd)
{
    char        tmp[BUFFER_SIZE + 1u];
    int         len;

    if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || !fd)
        return (NULL);
    if (!read(fd, tmp, BUFFER_SIZE))
        return(NULL);
    len = 0;
    while(tmp[len] && len != BUFFER_SIZE)
    {
        if (tmp[len] == '\n')
            return (ft_line(tmp, len));
        len++;
    }
    return (NULL);
}

int main()
{
    int fd = open("text.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    return (0);
}
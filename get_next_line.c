#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char    *ft_line(char *tmp, int len)
{
    char    *str;
    int     idx;

    str = malloc(sizeof(char) * (len + 1));
    idx = -1;
    while(++idx < len + 1)
        str[idx] = tmp[idx];
    str[idx] = '\0';
    return (str);
}

char    *get_next_line(int fd)
{
    static char buff[BUFFER_SIZE + 1u];
    char    *join;
    int  len;
    int  size;       

    if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd < 0)
        return (NULL);
    size = read(fd, buff, BUFFER_SIZE);
    if (size <= 0)
        return(NULL);
    buff[size] = '\0';
    len = 0;
    while(buff[len] && len < size)
    {
        if (buff[len] == '\n')
            return (ft_line(buff, len));
        len++;
    }
    if (size > 0)
    {
        join = malloc(size);
        read(fd, join, BUFFER_SIZE);
        join = ft_strjoin(join, buff);
    }
    return (NULL);
}

int main()
{
    char *print;
    int fd = open("text.txt", O_RDONLY);
    print = get_next_line(fd);
    while(print)
    {
    printf("%s", print);
    free(print);
    print = get_next_line(fd);
    }
    return (0);
}
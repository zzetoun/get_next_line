#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char    *ft_read_file(char *buff, int fd)
{
    char        *str;
    int         len;

    str = malloc(BUFFER_SIZE + 1);
    if (!str)
        return (NULL);
    len = 1;
     while (!ft_strchr(buff, '\n') && len > 0)
    {
        len = read(fd, str, BUFFER_SIZE);
        if (len < 0)
        {
            free(buff);
            buff = NULL;
            free(str);
            str = NULL;
            return (NULL);
        }
        str[len] = '\0';
        buff = ft_strjoin(buff, str);
    }
    free(str);
    return (buff);
}

char    *ft_line(char *buff)
{
    char    *str;
    int     idx;

    if (!ft_strlen(buff))
        return (NULL);
    idx = 0;
    while (buff[idx] && buff[idx] != '\n')
        idx++;
    str = malloc(idx + 2);
    if (!str)
        return (NULL);
    str[idx + 1] = '\0';
    while (idx != -1)
    {
        str[idx] = buff[idx];
        idx--;
    }
    return (str);
}

char    *ft_line_remain(char *buff)
{
    char    *remain;
    int     idx;
    int     jdx;

    idx = 0;
    while (buff[idx] && buff[idx] != '\n')
        idx++;
    if (!buff[idx])
        return (NULL);
    remain = malloc((ft_strlen(buff) + 1) - idx);
    if (!remain)
        return (NULL);
    idx++;
    jdx = 0;
    while (buff[idx])
        remain[jdx++] = buff[idx++];
    remain[jdx] = '\0';
    free(buff);
    return (remain);
}

char    *get_next_line(int fd)
{
    static char *buff;
    char        *print;
    
    if (BUFFER_SIZE > INT_MAX || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buff = ft_read_file(buff, fd);
    if (!buff)
        return (NULL);
    print = ft_line(buff);
    buff = ft_line_remain(buff);
    return (print);
}

int main()
{
    char    *print2;
    int     fd;
    int     count;
    
    fd = open("text.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error opening file");
        return (1);
    }
    count = 0;
    while (1)
    {
        print2 = get_next_line(fd);
        if (print2 == NULL)
            break ;
        count++;
        printf("[%d]:%s\n", count, print2);
        free(print2);
        print2 = NULL;
    }
    close(fd);
    return (0);
}
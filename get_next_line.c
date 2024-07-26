#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char    *ft_read_file(char *buff, int fd)
{
    char        *str;
    char        *tmp;
    int         len;

    str = malloc(BUFFER_SIZE + 1u);
    if (!str)
        return (NULL);
    len = 1;
     while (len > 0)
    {
        len = read(fd, str, BUFFER_SIZE);
        if (len < 0)
        {
            free(str);
            return (NULL);
        }
        str[len] = '\0';
        tmp = ft_strjoin(buff, str);
        ft_strcpy(buff, tmp);
        if (!ft_strchr(buff, '\n'))
            break;
    }
    free(str);
    return (buff);
}

char    *ft_line(char *buff)
{
    char    *str;
    int     idx;

    if (buff == NULL)
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

    if (!ft_strlen(buff))
        return (NULL);
    idx = 0;
    while (buff[idx] && buff[idx] != '\n')
        idx++;   
    jdx = idx;
    if (!buff[idx])
        return (NULL);
    while (buff[jdx])
        jdx++;
    remain = malloc((jdx - idx) + 1);
    if (!remain)
        return (NULL);
    jdx = 0;
    while (buff[idx])
        remain[jdx++] = buff[idx++];
    remain[jdx] = '\0';
    return (remain);
}

char    *get_next_line(int fd)
{
    static char buff[BUFFER_SIZE + 1u];
    char        *tmp;
    char        *print;
    
    if (BUFFER_SIZE > INT_MAX || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    tmp = ft_read_file(buff, fd);
    ft_strcpy(buff, tmp);
    print = ft_line(buff);
    tmp = ft_line_remain(buff);
    ft_strcpy(buff, tmp);
    return (print);
}

int main()
{
    char    *print;
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
        print = get_next_line(fd);
        if (print == NULL)
            break ;
        count++;
        printf("[%d]:%s\n", count, print);
        free(print);
        print = NULL;
    }
    close(fd);
    return (0);
}
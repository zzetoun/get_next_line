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
    char        *line;
    char        *tmp;
    char        *tmpbuff;
    char        *join;
    int         len;
    int         size;


    if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd < 0)
        return (NULL);
   line = NULL;
   while (1)
   {
        size = read(fd, buff, BUFFER_SIZE);
        if (size <= 0)
            return(line);
        buff[size] = '\0';
        len = 0;
        while(len < size)
        {
            if (buff[len] == '\n')
            {
            tmp = ft_line(buff, len);
            if (line)
            {
                join = ft_strjoin(line, tmp);
                free(tmp);
                free(line);
                tmp = join;
            }
            tmpbuff = ft_substr(buff, len + 1, size - len - 1);
            ft_strlcpy(buff, tmpbuff, size - len);
            free(tmpbuff);
            return (tmp);
            }
        len++;
        }
        if (!line)
           line = ft_strjoin("", buff);
        else
        {
        tmp = ft_strjoin(line, buff);
        free(line);
        line = tmp;
        }
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
    close(fd);
    return (0);
}
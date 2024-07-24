#include "get_next_line.h"

int ft_strlen(char *str)
{
    if (!str)
        return (0);
    return (ft_strlen(str + 1) + 1);
}

char    *ft_strjoin(char *join, char *buff)
{
    char    *str;
    int idx;
    int jdx;

    if (!join || !buff)
        return (NULL);
    str = malloc(ft_strlen(join) + ft_strlen(buff) + 1);
    if (!str)
        return (free(join), NULL);
    idx = 0;
    jdx = 0;
    while(join[jdx])
        str[idx++] = join[jdx++];
    jdx = 0;
    while(buff[jdx])
        str[idx++] = buff[jdx++];
    str[idx] = '\0';
    return (free(join), str);
}
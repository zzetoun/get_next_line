#include "get_next_line.h"
#include <stdio.h>

int ft_strlen(char *str)
{ 
   int  len;

   len = 0;
   while (str[len])
        len++;
    return (len);
}

char    *ft_strjoin(char *buff, char *str)
{
    char    *join;
    int     idx;
    int     jdx;

    if (!buff)
    {
        buff = malloc(sizeof(char));
        buff[0] = '\0';
    }
    if (!buff || !str)
        return (NULL);
    join = malloc(ft_strlen(str) + ft_strlen(buff) + 1);
    if (!join)
        return (NULL);
    idx = -1;
    while(buff[++idx])
        join[idx] = buff[idx];
    jdx = 0;
    while(str[jdx])
        join[idx++] = str[jdx++];
    join[idx] = '\0';
    free(buff);
    return (join);
}

char	*ft_strchr(char *buff, int c)
{
    int idx;

    idx = 0;
	while (buff[idx] && buff[idx] != c)
		idx++;
	if (buff[idx] == c)
		return (buff + idx);
	return (0);
}
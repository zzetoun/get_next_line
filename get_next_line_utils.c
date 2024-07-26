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
    int idx;
    int jdx;

    join = malloc(ft_strlen(str) + ft_strlen(buff) + 1);
    if (!join)
        return (NULL);
    idx = 0;
    jdx = 0;
    while(buff && buff[jdx])
        join[idx++] = buff[jdx++];
    jdx = 0;
    while(str[jdx])
        join[idx++] = str[jdx++];
    join[idx] = '\0';
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

int  ft_strcpy(char *buff, char *tmp)
{
	int	idx;

	idx = 0;
    if (!tmp)
    {
        buff = NULL;
        return (0);
    }
	while (tmp[idx])
	{
		buff[idx] = tmp[idx];
		idx++;
	}
	buff[idx] = '\0';
	while (tmp[idx])
		idx++;
	return (idx);
}
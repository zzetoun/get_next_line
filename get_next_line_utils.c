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

char    *ft_strjoin(char *join, char *buff)
{
    char    *str;
    int idx;
    int jdx;

    if (!buff)
        return (NULL);
    str = malloc(ft_strlen(join) + ft_strlen(buff) + 1);
    if (!str)
        return (NULL);
    idx = 0;
    jdx = 0;
    while(join && join[jdx])
        str[idx++] = join[jdx++];
    jdx = 0;
    while(buff[jdx])
        str[idx++] = buff[jdx++];
    str[idx] = '\0';
    return (str);
}

char    *ft_substr(char *buff, int start, int len)
{
	int     idx;
    int     jdx;
	char	*str;

	str = (char*)malloc(len + 1);
	if (!str)
		return (NULL);
	idx = -1;
	jdx = 0;
	while (buff[++idx])
	{
		if (idx >= start && jdx < len)
		{
			str[jdx] = buff[idx];
			jdx++;
		}
	}
	str[jdx] = '\0';
	return (str);
}

int  ft_strlcpy(char *buff, char *tmpbuff, int size)
{
	int	idx;

	idx = 0;
	if (size > 0)
	{
		while (tmpbuff[idx] && idx < (size - 1))
		{
			buff[idx] = tmpbuff[idx];
			idx++;
		}
		buff[idx] = 0;
	}
	while (tmpbuff[idx])
		idx++;
	return (idx);
}
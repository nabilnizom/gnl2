#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static  t_struct rd;
    char    *ret;

    if(ft_strlen(rd.read) == 0)
        initialize (rd.read, &rd.index, &rd.n_read, fd);
    if(rd.n_read <= 0)
        return (NULL);
    ret = (char *)malloc(sizeof(char) * rd.n_read);
    ft_bzero(ret, rd.n_read);
    while (rd.n_read && rd.n_read > rd.index)
    {
        rd.index = find_newline(rd.read);
        ret = read_to_ret(rd.read, ret, &rd.index, &rd.n_read);
        if (ft_strchr(ret, '\n'))
            return (ret);
        else
            initialize (rd.read, &rd.index, &rd.n_read, fd);
    }
    return(ret);
}

void    initialize(char *rd, int *index, int *n_read, int fd)
{
    if (ft_strlen(rd) == 0)
    {
        *n_read = read(fd, rd, BUFFER_SIZE);
        *index = -1;
    }
}

int find_newline(char *read)
{
    int i;
    
    i = 0;
    while (read[i] != '\n' && read[i])
            i++;
    return(i);
}

char    *read_to_ret(char *read, char *ret, int *i, int *n)
{
    char    temp_char;
    char    *temp_str;
    
    temp_char = 0;
    if (*i < *n)
    {
        temp_char = read[*i + 1];
        read[*i + 1] = '\0';
    }
    if (!(*ret))
        temp_str = ft_strdup(read);
    else
        temp_str = ft_strjoin(ret, read);
    if (temp_char != 0)
        read[*i + 1] = temp_char;
    free(ret);
    if ((*i + 1) == *n)
        ft_bzero(read, BUFFER_SIZE + 1);
    else
    {
        move_read(read, *i + 1);
        *n -= 1;
    }
    return (temp_str);
}

void    move_read(char  *read, int i)
{
    int j;

    j = 0;
    while (read[i])
    {
        read[j] = read[i];
        j++;
        i++;
    }
    ft_bzero(&read[j], (BUFFER_SIZE + 1 - j));
}

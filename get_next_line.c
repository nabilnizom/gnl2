#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

#include <stdio.h>

char	*rd_to_ret(char *ret, char *rd, int i, int n)
{
	char	*temp;
	char	tempchar;

	tempchar = rd[i+1];
	if (i < n)
		rd[i + 1] = 0;
	temp = ft_strjoin(ret, rd);
	rd[i + 1] = tempchar;
	free(ret);
	return(temp);
}

char	*rdold_to_ret(char	*ret, char	*rd, int i)
{
	char	*temp;
	int		j;
	char	tempchar;

	j = i + 1;
	tempchar = 0;
	while (rd[j] && rd[j] != '\n')
		j++;
	if (rd[j] == '\n')
	{
		tempchar = rd[j];
		rd[j] = 0;
	}
	temp = ft_strjoin(ret, &rd[i]);
	if (tempchar != 0)
	{
		rd[j] = tempchar;
		i = j;
	}
	else
		ft_bzero(rd, BUFFER_SIZE);
	free(ret);
	return(temp);
}

int		check_nl(char	*rd)
{
	int	i;

	i = 0;
	while (rd[i] != '\n' && rd[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static t_struct	rd;
	char			*ret;

	if (read(fd, NULL, 0 < 0))
		return (NULL);
	ret = (char *)malloc(sizeof(char *) * rd.n_read);
	if (rd.index > 0)
		 ret = rdold_to_ret(ret, rd.rd, rd.index + 1);
	rd.n_read = read(fd, rd.rd, BUFFER_SIZE);
	if (rd.n_read == 0 && rd.index == 0)
	{
		free(ret);
		return(NULL);
	}
	while (ft_strchr(ret, '\n') == 0 && rd.n_read)
	{
		rd.index = check_nl(rd.rd);
		ret = rd_to_ret(ret, rd.rd, rd.index, rd.n_read);
		if (ft_strchr(rd.rd, '\n' == 0))
			ft_bzero(rd.rd, rd.n_read);
		if (rd.index == rd.n_read && ft_strchr(rd.rd,'\n') == NULL)
		{
			rd.n_read = read(fd, rd.rd, BUFFER_SIZE);
			rd.index = 0;
		}
		else
			return (ret);
	}
	return (ret);
}

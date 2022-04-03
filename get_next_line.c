#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

#include <stdio.h>

char	*rd_to_unret(char *unret, char *rd, int i)
{
	if (ft_strchr(rd, '\n') == &rd[i])
	{
		unret = ft_strjoin(unret, &rd[i]);
		rd[i] = 0;
	}
	return (unret);
}

char	*rd_to_ret(char *ret, char *rd)
{
	ret = ft_strjoin(ret, rd);
	ft_bzero(rd, BUFFER_SIZE);
	return(ret);
}

char	*get_next_line(int fd)
{
	char		*rd;
	int			i;
	char		*ret;
	static char	*unret = NULL;

	if (unret)
		ret = unret;
	else
		ret = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	unret = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rd = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((i = -1) < (fd - 3) && (ft_strlen(unret) == 0) && read(fd, rd, BUFFER_SIZE))
	{
		while (i++ < BUFFER_SIZE && (ft_strlen(unret) == 0))
			unret = rd_to_unret(unret, rd, i);
		ret = rd_to_ret(ret, rd);
	}
	if (ft_strlen(ret) == 0 || fd < 3)
		free(unret);
	if (ft_strlen(ret) == 0 || fd < 3)
		ret = NULL;
	free (rd);
	return (ret);
}
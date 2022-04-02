#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

char	*rd_to_ret(char *unret, char *rd, int i)
{
	unret = ft_strjoin(unret, &rd[i]);
	rd[i] = 0;
	return (unret);
}

char	*get_next_line(int fd)
{
	char		*rd;
	int			i;
	char		*ret;
	static char	*unret = NULL;

	if (unret != NULL)
		ret = ft_strdup(unret);
	free(unret);
	unret = malloc(sizeof(char) * (4 + 1));
	rd = malloc(sizeof(char) * (4 + 1));
	while (read(fd, rd, 4 && ft_strlen(unret) == 0))
	{
		i = -1;
		while (i++ <= 4 && ft_strlen(unret) == 0)
		{
			if (ft_strchr(rd, '\n') == &rd[i])
				unret = rd_to_ret(unret, rd, i);
		}
		ret = ft_strjoin(ret, rd);
		ft_bzero(rd, 4);
	}
	free (rd);
	return (ret);
}
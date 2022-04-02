#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*rd_to_ret(char *unret, char *rd, int i)
{
	if (ft_strchr(rd, '\n') == &rd[i])
	{
		unret = ft_strjoin(unret, &rd[i]);
		rd[i] = 0;
	}
	return (unret);
}

char	*get_next_line(int fd)
{
	char		*rd;
	int			i;
	char		*ret;
	static char	*unret = NULL;

	if (!fd)
		return (NULL);
	if (unret)
		ret = unret;
	else
		ret = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	unret = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rd = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((ft_strlen(unret) == 0) && read(fd, rd, BUFFER_SIZE))
	{
		i = -1;
		while (i++ < BUFFER_SIZE && (ft_strlen(unret) == 0))
			unret = rd_to_ret(unret, rd, i);
		ret = ft_strjoin(ret, rd);
		ft_bzero(rd, BUFFER_SIZE);
	}
	if (!ret)
		free(unret);
	free (rd);
	return (ret);
}
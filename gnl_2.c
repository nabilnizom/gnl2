#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char*)str;
	while (*ptr)
	{
		if (*ptr == c)
			return(ptr);
		ptr++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*sjoin;
	int		i;

	len_s1 = ft_strlen((char*)s1);
	len_s2 = ft_strlen((char*)s2);
	sjoin = (char*)malloc((len_s1 + len_s2) * sizeof(char));
	i = 0;
	while (i < len_s1)
	{
		sjoin[i] = s1[i];
		i++;
	}
	while (i < (len_s1 + len_s2))
	{
		sjoin[i] = s2[i - len_s1];
		i++;
	}
	return(sjoin);
}

void ft_bzero(void *str, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
		((unsigned char*)str)[i++] = '\0';
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		len;
	int		i;

	len = ft_strlen((char *)str);
	ptr = (char*)malloc(sizeof(char) * len);
	if (ptr == NULL)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		*rd;
	int			BUFFER_SIZE = 4;
	int			i;
	char		*ret;
	static char	*unret = NULL;

	ret = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (unret == NULL)
		unret = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	else
	{
		ret = ft_strdup(unret);
		ft_bzero(unret, BUFFER_SIZE);
	}
	rd = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (read(fd, rd, BUFFER_SIZE))
	{
		i = 0;
		while (i <= BUFFER_SIZE)
		{
			if (ft_strchr(rd, '\n') == &rd[i])
			{
				unret = ft_strjoin(unret, &rd[i+1]);
				rd[i] = 0;
				ret = ft_strjoin(ret, rd);
				free(rd);
				return(ret);
			}
			else if (i == BUFFER_SIZE)
					ret = ft_strjoin(ret, rd);
			i++;
		}
	}
	free(rd);
	return(ret);
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	return (0);
}
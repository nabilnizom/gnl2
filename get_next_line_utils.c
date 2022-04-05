#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

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
	sjoin = (char*)malloc((len_s1 + len_s2) * sizeof(char) + 1);
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
	sjoin[i] = 0;
	return(sjoin);
}

void ft_bzero(void *str, size_t n)
{
	size_t	i;

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
	ptr = (char *)malloc(sizeof(char) * len);
	i = 0;
	if (ptr == NULL)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}

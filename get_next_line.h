#ifndef GET_NEXT_LINE_
# define GET_NEXT_LINE_
# include <stddef.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *str, size_t n);
char	*ft_strdup(const char *str);
char	*get_next_line(int fd);

#endif
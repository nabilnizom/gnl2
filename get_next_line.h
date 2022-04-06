#ifndef GET_NEXT_LINE_
# define GET_NEXT_LINE_
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_struct
{
		int		index;
		int		n_read;
		char	read[BUFFER_SIZE + 1];
}				t_struct;

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *str, size_t n);
char	*ft_strdup(const char *str);
char	*get_next_line(int fd);
int		find_newline(char *read);
char	*read_to_ret(char *read, char *ret, int *i, int *n);
void	move_read(char  *read, int i);
void	initialize(char *rd, int *index, int *n_read, int fd);

#endif

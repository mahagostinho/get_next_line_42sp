#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

char	*get_next_line(int fd);
char 	*ft_read_and_keep(int fd, char *save);
char    *ft_get_line(char *save);
char    *ft_save_rest(char *save);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
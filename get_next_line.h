#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>//RETIRAR TAMBÉM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <fcntl.h>//RETIRAR!!!!!!!!!!!!!!!!!!!!!!!!!!
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*read_and_save(int fd, char *save);
char	*get_line(char *save);
char	*update_save(char *save);
void    ft_free_ptr(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
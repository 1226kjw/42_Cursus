#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

int		get_next_line(int fd, char **line);
size_t	ft_len(const char *s);
char	*ft_dup(const char *s);
int		ft_join(char **s, char *s2);
int		ft_remainder(int fd, char *remain[], char **line);
int		freeall(char *buf, char **line);

#endif

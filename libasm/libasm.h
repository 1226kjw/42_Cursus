#ifndef LIBASM_H
# define LIBASM_H
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_strlen(char *str);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);

#endif

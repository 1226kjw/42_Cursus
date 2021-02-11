CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRCS = $(wildcard ./ft_*.c)
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -crs $@ $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

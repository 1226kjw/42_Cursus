CC = gcc
CFLAGS = -Wall -Wextra #-Werror

NAME = push_swap
INCLUDE = -Iincludes/
SRCS = $(wildcard ./srcs/*.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean :
	rm -f $(OBJS) $(DEPS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.c.o :
	$(CC) $(CFLAGS) -MD -c -o $@ $< $(INCLUDE)

-include $(DEPS)

.PHONY: all clean fclean re

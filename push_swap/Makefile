CC = gcc
CFLAGS = -Wall -Wextra #-Werror

NAME = push_swap
CHECKER = checker
INCLUDE = -Iincludes/
SRCS_P = $(wildcard ./srcs_p/*.c)
OBJS_P = $(SRCS_P:.c=.o)
DEPS_P = $(SRCS_P:.c=.d)
SRCS_C = $(wildcard ./srcs_c/*.c)
OBJS_C = $(SRCS_C:.c=.o)
DEPS_C = $(SRCS_C:.c=.d)

all : $(NAME) $(CHECKER)

$(NAME) : $(OBJS_P)
	$(CC) $(CFLAGS) $^ -o $@

$(CHECKER) : #$(OBJS_C)
#	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -f $(OBJS_P) $(DEPS_P) $(OBJS_C) $(DEPS_C)

fclean : clean
	rm -f $(NAME)

re : fclean all

.c.o :
	$(CC) $(CFLAGS) -MD -c -o $@ $< $(INCLUDE)

-include $(DEPS_P) $(DEPS_C)

.PHONY: all clean fclean re

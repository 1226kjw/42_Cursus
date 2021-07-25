CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
CHECKER = checker
INCLUDE = -Iincludes/
SRCS_P = $(addprefix ./srcs/,\
		 astar0.c astar1.c\
		 atob.c btoa.c\
		 board0.c board1.c board2.c\
		 inst0.c inst1.c\
		 list0.c list1.c\
		 priqueue.c\
		 utils0.c utils1.c) push_swap_main.c
OBJS_P = $(SRCS_P:.c=.o)
DEPS_P = $(SRCS_P:.c=.d)

SRCS_C = $(addprefix ./srcs/,\
		 get_next_line.c get_next_line_utils.c\
		 board0.c board1.c board2.c\
		 list0.c list1.c\
		 utils0.c utils1.c) checker_main.c
OBJS_C = $(SRCS_C:.c=.o)
DEPS_C = $(SRCS_C:.c=.d)

all : $(NAME) $(CHECKER)

$(NAME) : $(OBJS_P)
	$(CC) $(CFLAGS) $^ -o $@

$(CHECKER) : $(OBJS_C)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -f $(OBJS_P) $(DEPS_P) $(OBJS_C) $(DEPS_C)

fclean : clean
	rm -f $(NAME) $(CHECKER)

re : fclean all

.c.o :
	$(CC) $(CFLAGS) -MD -c -o $@ $< $(INCLUDE)

-include $(DEPS_P) $(DEPS_C)

.PHONY: all clean fclean re

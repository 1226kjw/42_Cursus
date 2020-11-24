CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SUB = ./libft/libft.a
SRCS = $(wildcard ./ft_*.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SUB) $(OBJS)
	cp $(SUB) $(NAME)
	ar -cr $@ $(OBJS)

$(SUB) :
	make all -C ./libft

clean :
	make clean -C ./libft
	rm -f $(OBJS)

fclean : clean
	rm -f $(SUB)
	rm -f $(NAME)

re : fclean all

bonus : all

.c.o :
	$(CC) $(FLAGS) -c -o $@ $<

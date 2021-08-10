NAME	= account

CC		= clang++ 
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= Account.cpp test.cpp
OBJS	= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:				fclean all


.PHONY:			all clean fclean re

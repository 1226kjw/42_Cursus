NAME		= Megaphone

CC			= clang++ 
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)
DEPS		= $(SRCS:.cpp=.d)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -MD -c -o $@ $<

test:	$(NAME)
	./megaphone "shhhhh... I think the students are asleep..."
	./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
	./megaphone

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:				fclean all

-include $(DEPS)

.PHONY:			all clean fclean re test

NAME	= phonebook

CC		= clang++ 
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp Contact.cpp Phonebook.cpp
OBJS	= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I./includes

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

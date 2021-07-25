NAME 		= pipex

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror


LIBFT 		= libft.a
INCLUDE 	= ./includes/
SRCS_DIR 	= ./srcs/

SRCS		= $(addprefix $(SRCS_DIR),\
			  pipex.c\
			  redirect.c\
			  utils.c\
			  get_next_line.c\
			  get_next_line_utils.c)
OBJS 		= $(SRCS:.c=.o)
DEPS 		= $(SRCS:.c=.d)

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -L. -lft $(RL) $(RL_LIB)

$(LIBFT) :
	make all -C ./libft
	cp ./libft/libft.h $(INCLUDE)
	cp ./libft/libft.a ./

clean :
	make clean -C ./libft
	rm -f $(OBJS) $(DEPS)

fclean : clean
	rm -f $(LIBFT) ./libft/libft.a
	rm -f $(NAME)

re : fclean all

.c.o :
	$(CC) $(CFLAGS) -DBONUS=1 -MD -c -o $@ $< -I$(INCLUDE)

-include $(DEPS)

.PHONY: all clean fclean re bonus

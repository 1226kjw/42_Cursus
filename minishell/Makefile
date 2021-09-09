NAME 			= minishell

CC 				= gcc
CFLAGS	 		= -Wall -Wextra -Werror

LIBFT 			= libft.a
INCLUDE 		= includes/
SRCS_DIR 		= ./srcs/

RL				= -lreadline

SRCS 			= $(addprefix $(SRCS_DIR),\
				  builtin.c\
				  builtin_util.c\
				  env.c\
				  eof_handler.c\
				  exec.c\
				  init0.c init1.c\
				  list.c\
				  loop.c\
				  minishell.c\
				  parse0.c parse1.c\
				  pipe.c\
				  redirection0.c redirection1.c\
				  sig_handler.c\
				  utils0.c utils1.c\
				  )
OBJS 			= $(SRCS:.c=.o)
DEPS 			= $(SRCS:.c=.d)


all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -L. -lft $(RL) -lncurses

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
	$(CC) $(CFLAGS) -MD -c -o $@ $< -I$(INCLUDE)

-include $(DEPS)

.PHONY: all clean fclean re

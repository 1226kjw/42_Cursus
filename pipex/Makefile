NAME 		= pipex
NAME_B		= pipex

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror

LIBFT 		= libft.a
INCLUDE 	= ./includes/
SRCS_DIR 	= ./srcs/

SRCS		= $(addprefix $(SRCS_DIR),\
			  pipex_bonus.c\
			  redirect_bonus.c\
			  utils.c\
			  get_next_line.c\
			  get_next_line_utils.c\
			  )
OBJS 		= $(SRCS:.c=.o)
DEPS 		= $(SRCS:.c=.d)

all : $(NAME)

bonus : all

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -L. -lft

$(LIBFT) :
	make all -C ./libft
	cp ./libft/libft.h $(INCLUDE)
	cp ./libft/libft.a ./

clean :
	make clean -C ./libft
	rm -f $(OBJS) $(DEPS) $(OBJS_B) $(DEPS_B)

fclean : clean
	rm -f $(LIBFT) ./libft/libft.a
	rm -f $(NAME)

re : fclean all

%.o : %.c
ifeq ($(MAKECMDGOALS), bonus)
	$(CC) $(CFLAGS) -DBONUS=1 -MD -c -o $@ $< -I$(INCLUDE)
else
	$(CC) $(CFLAGS) -MD -c -o $@ $< -I$(INCLUDE)
endif

-include $(DEPS) $(DEPS_B)

.PHONY: all clean fclean re bonus

NAME = a.out
SRCS = test.c

CC = gcc
FLAGS = -Wall -Wextra -Werror
MLXL = libmlx.a libmlx.dylib

MMS = minilibx_mms_20200219
OPENGL = minilibx_opengl_20191021



all: $(NAME)
	
$(NAME): $(SRCS) $(MLXL)
	$(CC) -o $@ $(SRCS) $(FLAGS) -L . -l mlx

$(MLXL) :
	make all -C $(MMS)
	make all -C $(OPENGL)


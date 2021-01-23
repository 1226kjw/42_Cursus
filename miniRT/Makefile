NAME = a.out

SRCS = $(addprefix $(SRCS_DIR),\
	   minirt.c\
	   parsing.c\
	   )
SRCS_DIR = ./srcs/

HDR_DIR = ./includes/

CC = gcc
FLAGS = -Wall -Wextra -Werror

MLXL = libmlx.a libmlx.dylib

MMS = ./minilibx_mms/
OPENGL = ./minilibx_opengl/



all: $(NAME)
	
$(NAME): $(SRCS) $(MLXL)
	$(CC) -o $@ $(SRCS) $(FLAGS) -I $(HDR_DIR) -L . -l mlx

$(MLXL) :
	make all -C $(MMS)
	make all -C $(OPENGL)
	cp $(MMS)libmlx.dylib ./
	cp $(OPENGL)libmlx.a ./


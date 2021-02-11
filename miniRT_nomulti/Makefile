CC = gcc
FLAGS = -Wall -Wextra #-Werror

NAME = a.out

SRCS_DIR = ./srcs/
HDR_DIR = ./includes/

SRCS = $(addprefix $(SRCS_DIR),\
		minirt.c\
		key.c\
		parsing.c\
		parsing_elem.c\
		element.c\
		sphere.c\
		plane.c\
		square.c\
		cylinder.c\
		triangle.c\
		intersect.c\
		images.c\
		multithreading.c\
		vector.c\
		utils/utils.c\
		utils/get_next_line.c\
		utils/get_next_line_utils.c\
		)

MLXL = libmlx.a libmlx.dylib
MMS = ./minilibx_mms/
OPENGL = ./minilibx_opengl/
LIBFT = libft.a

all: $(NAME)

$(NAME): $(SRCS) $(MLXL) $(LIBFT)
		   $(CC) -o $@ $(SRCS) $(FLAGS) -I $(HDR_DIR) -L . -l mlx -l ft

$(MLXL):
	make all -C $(MMS)
	make all -C $(OPENGL)
	cp $(MMX)libmlx.dylib ./
	cp $(OPENGL)libmlx.a ./

$(LIBFT):
	make all -C ./libft
	cp ./libft/libft.h $(HDR_DIR)
	cp ./libft/libft.a ./

clean:
	make clean -C ./libft
	rm -rf $(MLXL) $(LIBFT)

fclean: clean
	rm -rf $(NAME)

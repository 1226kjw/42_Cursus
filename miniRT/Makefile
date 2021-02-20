CC = gcc
FLAGS = -Wall -Wextra #-Werror

NAME = a.out

SRCS_DIR = ./srcs/
HDR_DIR = ./includes/

SRCS = $(addprefix $(SRCS_DIR),\
		camera0.c\
		camera1.c\
		circle.c\
		color0.c\
		color1.c\
		cone.c\
		cube.c\
		cylinder.c\
		element.c\
		hub.c\
		images.c\
		key.c\
		minirt.c\
		multithreading.c\
		object0.c\
		object1.c\
		object2.c\
		parsing.c\
		parsing_elem.c\
		plane.c\
		pyramid.c\
		shading.c\
		sphere.c\
		square.c\
		triangle.c\
		vector0.c\
		vector1.c\
		vector2.c\
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

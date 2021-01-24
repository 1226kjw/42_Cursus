NAME = a.out

SRCS = $(addprefix $(SRCS_DIR),\
		minirt.c\
		parse/parsing.c\
		parse/parsing_elem.c\
		parse/parsing_obj.c\
		\
		intersect/intersect.c\
		intersect/inter_sp.c\
		\
		vector/vecutils1.c\
		vector/vecutils2.c\
		\
		utils/ft_atoi.c\
		utils/get_next_line.c\
		utils/get_next_line_utils.c\
		utils/utils0.c\
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


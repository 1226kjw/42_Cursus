NAME = libasm.a

SRCS = $(wildcard ./*.s)

OBJS = $(SRCS:.s=.o)

EXEC = test.out

%.o : %.s
	nasm -f elf64 $< -o $@

$(NAME): $(OBJS) $(SRCS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(EXEC): $(NAME) main.c
	gcc main.c -L. -lasm -o $@

exec:
	./$(EXEC)

test: $(EXEC) exec

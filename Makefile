NAME = fillit
SRCS = valid.c bits.c fillit.c main.c read.c
OBJ = $(SRCS:.c=.o)
FLAGS =  -Wall -Wextra -Werror
FILES_C = find . -name "ft_*.c”
FIL_FILES = valid/valid.c read/read.c bit/bits.c

all: $(NAME)

$(NAME):
	clang $(FLAGS) -I libft/includes -c $(SRCS) -g
	clang -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft -g

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all
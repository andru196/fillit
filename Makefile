NAME = fillit
SRCS = valid.c bits.c bruter.c main.c read.c clear.c search_n_insert.c
OBJ = $(SRCS:.c=.o)
FLAGS =  -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang $(FLAGS) -I libft/includes -c $(SRCS) -g
	clang -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft -g

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all
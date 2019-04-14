NAME = fillit
SRCS = bruter.c fillit.c main.c read_n_valid.c clear.c search_n_insert.c
OBJ = $(SRCS:.c=.o)
FLAGS =  -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@clang $(FLAGS) -I libft/includes -c $(SRCS)
	@clang -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
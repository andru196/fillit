clang -Wall -Wextra -Werror -I gnl/libft/includes  -c gnl/get_next_line.c
clang -Wall -Wextra -Werror -I gnl/ -I gnl/libft/includes -c main.c
clang -o test_fil main.o get_next_line.o -I gnl/libft/includes -L gnl/libft/ -lft

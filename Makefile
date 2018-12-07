NAME := fillit
SRCS := 
OBJ = main.o count_func.o get_next_line.o
INCL := ./includes
FLAGS := -Wall -Wextra -Werror
LIB := ./libft

all: $(NAME)

$(NAME):
		@make -C libft/
		# @gcc $(FLAGS) -I $(INCL) -c $(SRCS)
		# @gcc $(FLAGS) -o $(NAME) $(OBJ) -L $(LIB) -lft

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm $(NAME)

re: fclean all
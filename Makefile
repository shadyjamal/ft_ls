NAME = ft_ls

DIR_LFT = libft

FLAGS = -Wall -Werror -Wextra

SRC = $(wildcard srcs/*.c)

INC = -Iincludes/

CC = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	$(CC) $(FLAGS) $(INC) $(OBJ) -Llibft/ -lft -o $(NAME)

srcs/%.o: srcs/%.c
	echo "\033[34m$^ \033[0m-> \033[1m\033[37m$@\033[0m"
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	echo "\033[31mDelete .o of $(NAME)\033[0m"
	@/bin/rm -f $(OBJ)
	@(cd $(DIR_LFT) && make clean)

fclean: clean
	echo "\033[31mDelete .o and $(NAME)\033[0m"
	@/bin/rm -f $(NAME)
	@(cd $(DIR_LFT) && make fclean)

re: fclean all

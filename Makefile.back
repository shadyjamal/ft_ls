NAME = ft_ls

SRC = $(wildcard srcs/*.c)

FLAGS := -Wall -Werror -Wextra

INC = -Iincludes/

CC = gcc

OBJ = $(patsubst %.c,%.o,$(SRC))

LIB = -Llibft/

all : $(NAME)

%.o : %.c 
	@$(CC) $(INC) -o $@ -c $<

$(NAME) : $(OBJ)
	@make -C libft/
	@$(CC) $(FLAGS) $(INC) $(LIB) -o $@ $^

clean	: 
	@rm -rf srcs/*.o

fclean	: clean 
	@rm -rf $(NAME)

re : fclean all

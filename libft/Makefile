NAME = libft.a

SRC = $(wildcard *.c)

FLAGS = -Wall -Wextra -Werror

CC = gcc $(FLAGS)

OBJ = $(patsubst %.c,%.o,$(SRC))

LIB = ar rc $(NAME) $(OBJ)

all : $(NAME)

%.o : %.c 
	@$(CC) -o $@ -c $<

$(NAME) : $(OBJ)
	@$(LIB)
	@ranlib $(NAME)

clean	: 
	@rm -f *.o

fclean	: clean
	@rm -f $(NAME)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjamal <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 16:28:39 by cjamal            #+#    #+#              #
#    Updated: 2019/11/12 16:28:40 by cjamal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

DIR_LFT = libft

FLAGS = -Wall -Werror -Wextra -g

SRC = 	srcs/display.c\
		srcs/displaydetail.c\
		srcs/freecontent.c\
		srcs/getdata.c\
		srcs/lserror.c\
		srcs/lsmain.c\
		srcs/main.c\
		srcs/parsing.c\
		srcs/sortlst.c\
		srcs/utilsdisplay.c\
		srcs/size.c\
		srcs/utilssort.c

INC = -Iincludes/

CC = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	$(CC) $(FLAGS) $(INC) $(OBJ) -Llibft/ -lft -o $(NAME)

srcs/%.o: srcs/%.c
	echo "$^->$@"
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	echo "Delete .o of $(NAME) and Libft"
	@/bin/rm -f $(OBJ)
	@(cd $(DIR_LFT) && make clean)

fclean: clean
	echo "Delete .o and $(NAME)"
	@/bin/rm -f $(NAME)
	@(cd $(DIR_LFT) && make fclean)

re: fclean all

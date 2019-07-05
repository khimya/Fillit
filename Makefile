# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 20:45:55 by ybenbrai          #+#    #+#              #
#    Updated: 2019/06/24 05:47:26 by ybenbrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c tetris.c tetris_tools.c grid.c fillit.c get_next_line.c
OBJ = *.o
LIB = libft/libft.a
FLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB)
clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
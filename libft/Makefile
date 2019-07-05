# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenbrai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/27 10:16:09 by ybenbrai          #+#    #+#              #
#    Updated: 2019/03/29 21:09:36 by ybenbrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c *.c
	ar rc $(NAME) *.o

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)
re : fclean all

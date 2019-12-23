#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 18:25:21 by vpelivan          #+#    #+#              #
#    Updated: 2018/12/31 10:06:46 by vpelivan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRCS =	srcs/main.c srcs/map.c srcs/calculate.c srcs/tetr_cut.c\
		srcs/validator.c

OBJ = main.o map.o calculate.o tetr_cut.o validator.o

INC = srcs/fillit.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@make -C libft
	@gcc $(FLAGS) -I $(INC) -c $(SRCS)
	@gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 14:11:32 by thinguye          #+#    #+#              #
#    Updated: 2021/10/12 14:24:31 by thinguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = lem_in.h

NAME = lem_in

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRC = src/lem_in.c \
		src/helper.c \
		src/check_form.c \
		src/parse_info.c \
		src/find_path.c

OBJ = lem_in.o \
		helper.o \
		check_form.o \
		parse_info.o \
		find_path.o


all: $(NAME)

$(NAME):
	make -C libft/
	@gcc $(FLAGS) -c $(SRC)
	@gcc $(OBJ) $(LIBFT) -o lem_in
	make clean

clean:
	make -C libft clean
	rm -rf lem_in.h.gch $(OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
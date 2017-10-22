# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 22:31:41 by ghippoda          #+#    #+#              #
#    Updated: 2017/05/16 19:06:52 by ghippoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRCS = ./sources/map.c ./sources/dessin.c ./sources/ft_init_param.c \
	   ./sources/mvt.c ./sources/main.c ./sources/ft_creatmap.c \
		./sources/wolf_algo.c ./sources/errors.c
FLAGS = -Wall -Wextra -Werror -Ofast

FLAGS_SDL = -framework SDL2 -I/Library/Frameworks/SDL2.framework/Headers \
			-L./libft -lft

OBJ = ./sources/map.o ./sources/dessin.o ./sources/ft_init_param.o \
	  ./sources/mvt.o ./sources/main.o ./sources/ft_creatmap.o \
		./sources/wolf_algo.o ./sources/errors.o

HEADER = ./includes/

LIB = libft.a

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAGS_LBX) $(FLAGS_SDL) $(OBJ) -o $(NAME) 

%o: %c
	gcc $(FLAGS) -I$(HEADER) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft

re: fclean all

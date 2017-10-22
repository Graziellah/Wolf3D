# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 14:32:22 by ghippoda          #+#    #+#              #
#    Updated: 2017/04/25 14:42:12 by ghippoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	   ft_isprint.c ft_memalloc.c ft_memchr.c \
	   ft_memdel.c ft_memmove.c ft_putchar.c ft_putnbr_fd.c ft_putchar_fd.c\
	   ft_putendl_fd.c ft_putstr_fd.c \
	   ft_putendl.c ft_putstr.c ft_strcat.c ft_strchr.c ft_strclr.c \
	   ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	   ft_striter.c ft_striteri.c ft_strjoin.c ft_toupper.c ft_tolower.c \
	   ft_strsub.c ft_strrchr.c ft_strnequ.c \
	   ft_strncpy.c ft_strncmp.c ft_strmapi.c ft_strmap.c \
	   ft_strlen.c ft_strnew.c ft_atoi.c ft_putnbr.c ft_bzero.c ft_strncat.c \
	   ft_memset.c ft_strsplit.c ft_strlcat.c ft_memcmp.c ft_memcpy.c \
	   ft_memccpy.c ft_strstr.c ft_strtrim.c ft_strnstr.c ft_itoa.c \
	   ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
	   ft_lstnew.c ft_intlen.c ft_swap.c ft_strrev.c ft_strcmp_pos.c \
	   ft_sqrt.c ft_range.c ft_is_prime.c ft_search_replace.c ft_strjoinf.c \
	   ft_strsubf.c get_next_line.c ft_strmerge.c

FLAGS = -c -Wall -Werror -Wextra

OBJ  = ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o \
	   ft_isprint.o ft_memalloc.o ft_memchr.o \
	   ft_memdel.o ft_memmove.o ft_putchar.o ft_putnbr_fd.o ft_putchar_fd.o \
	   ft_putendl_fd.o ft_putstr_fd.o \
	   ft_putendl.o ft_putstr.o ft_strcat.o ft_strchr.o ft_strclr.o \
	   ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o \
	   ft_striter.o ft_striteri.o ft_strjoin.o ft_toupper.o ft_tolower.o \
	   ft_strsub.o ft_strrchr.o ft_strnequ.o \
	   ft_strncpy.o ft_strncmp.o ft_strmapi.o ft_strmap.o \
	   ft_strlen.o ft_strnew.o ft_atoi.o ft_putnbr.o ft_bzero.o ft_strncat.o \
	   ft_memset.o ft_strsplit.o ft_strlcat.o ft_memcmp.o ft_memcpy.o \
	   ft_memccpy.o ft_strstr.o ft_strtrim.o ft_strnstr.o ft_itoa.o \
	   ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o \
	   ft_lstnew.o ft_intlen.o ft_swap.o ft_strrev.o ft_strcmp_pos.o \
	   ft_sqrt.o ft_range.o ft_is_prime.o ft_search_replace.o ft_strjoinf.o \
	   ft_strsubf.o get_next_line.o ft_strmerge.o

HEADER = libft.h

all: $(NAME)

$(NAME) :
	gcc $(FLAGS) $(SRCS) -I$(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean:clean
	/bin/rm -f $(NAME)
	
re:fclean all


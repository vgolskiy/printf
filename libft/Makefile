# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 14:24:26 by mskinner          #+#    #+#              #
#    Updated: 2020/06/11 15:21:22 by mskinner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Werror -Wextra

SRC =	ft_calloc.c	ft_itoa_base.c	ft_putstr.c		ft_toupper.c	ft_bzero.c		ft_isdigit.c	ft_putchar.c	ft_strlen.c\
		ft_memcpy.c	ft_strdup.c		ft_isalpha.c	ft_strchr.c		ft_strrchr.c	ft_substr.c		ft_isascii.c	ft_strcmp.c\
		

OBJ = $(SRC:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@ranlib $@
	
%.o: %.c $(HEADER)
	@gcc $(FLAG) -I $(HEADER) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

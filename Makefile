# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 14:24:26 by mskinner          #+#    #+#              #
#    Updated: 2020/06/15 14:29:23 by mskinner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

BONUS = 0

LIBFT = libft.a
LIBFT_H = libft.h
LIB_DIR = libft/

FLAG = -Wall -Werror -Wextra

SRC =	ft_print_ptr.c	ft_printf.c		ft_init_format.c	ft_parse_format.c	ft_parse_flag.c	ft_print_str.c		ft_print_char.c\
		ft_print_int.c	ft_print_uxx.c	ft_free_str.c		ft_free_substr.c	ft_parse_star.c ft_parse_ntype.c	ft_parse_prec.c\
		ft_parse_zero.c

OBJ = $(SRC:.c=.o)
SRC_BONUS = $(patsubst %.c, %_bonus.c, $(SRC))
OBJ_BONUS = $(SRC_BONUS:.c=.o)

HDR = printf.h
HDR_BONUS = printf_bonus.h

ifdef WITH_BONUS
	OBJ_FILES = $(OBJ_BONUS)
	HEADER = $(HDR_BONUS)
else
	OBJ_FILES = $(OBJ)
	HEADER = $(HDR)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(MAKE) -C $(LIB_DIR)
	@cp $(LIB_DIR)$(LIBFT) ./$(NAME)
	@ar rcs $@ $^
	@ranlib $@
	
%.o: %.c $(HEADER)
	@gcc $(FLAG) -I $(HEADER) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB_DIR)$(LIBFT)

re: fclean all

bonus:
	@$(MAKE) WITH_BONUS=1 all

.PHONY: all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 10:12:24 by ieschall          #+#    #+#              #
#    Updated: 2021/10/09 18:21:02 by ieschall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEAD = ft_printf.h

FLAGS = -Wall -Wextra -Werror

C_FILES =	ft_printf.c \
			parser.c \
			hex_print.c \
			int_print.c \
			char_print.c \
			pointer_print.c \
			string_print.c \
			unsigned_print.c

O_FILES = $(C_FILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c $(HEAD)
		clang $(FLAGS) -c $<

$(NAME): $(O_FILES)
		make -C libft
		cp libft/libft.a $(NAME)
		ar rc $(NAME) $(O_FILES)
		ranlib $(NAME)

clean:
		rm -rf $(O_FILES)
		make clean -C libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C libft

re:		fclean all

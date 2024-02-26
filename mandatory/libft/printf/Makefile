# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 17:15:55 by anqabbal          #+#    #+#              #
#    Updated: 2024/01/01 17:33:09 by anqabbal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

FILES = ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_print_hexa.c ft_printf.c ft_print_unsigned.c ft_print_address.c

OBJF = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJF)
	ar rc $(NAME) $^

%.o : %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJF)

fclean : clean
	rm -f $(NAME)

re : fclean all
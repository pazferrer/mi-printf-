# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pferrer- <pferrer-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 16:48:13 by pferrer-          #+#    #+#              #
#    Updated: 2024/03/14 14:23:33 by pferrer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar -rcs

C_FILES = ft_printf.c ft_printhexm.c print_c.c print_p.c

O_FILES = $(C_FILES:.c=.o)

NAME = libftprintf.a

#Targets

all: $(NAME)

$(NAME): $(O_FILES)
	$(AR) $(NAME) $(O_FILES)

%.o: %.c ft_printf.h Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ compilado"

clean:
	@rm -f $(O_FILES)
	@echo "$(O_FILES) deleted"

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

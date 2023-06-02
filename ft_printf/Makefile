# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 19:29:37 by feden-pe          #+#    #+#              #
#    Updated: 2023/04/25 22:53:01 by feden-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = ft_printf.c \
	 ft_number.c \
	 ft_words.c
OFILES = $(CFILES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
RM = rm -f

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

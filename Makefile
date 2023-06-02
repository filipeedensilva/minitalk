# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 18:31:55 by feden-pe          #+#    #+#              #
#    Updated: 2023/06/02 13:10:19 by feden-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

EXCL = client

EXSV = server

RM = rm -f

FT_PRINTF = ./ft_printf/libftprintf.a

LIBFT = ./libft/libft.a

SRCCL = client.c

SRCSV = server.c

all:	$(EXSV) $(EXCL)

$(EXSV):	$(LIBFT) $(FT_PRINTF) $(SRCSV)
	$(CC) $(CFLAGS) $(SRCSV) $(FT_PRINTF) $(LIBFT) -o $(EXSV) -g

$(EXCL):	$(LIBFT) $(FT_PRINTF) $(SRCCL)
	$(CC) $(CFLAGS) $(SRCCL) $(FT_PRINTF) $(LIBFT) -o $(EXCL) -g

$(LIBFT):
	make -C ./libft

$(FT_PRINTF):
	make -C ./ft_printf

clean:
	make clean -C ./libft
	make clean -C ./ft_printf

fclean:	clean
	make fclean -C ./libft
	make fclean -C ./ft_printf
	$(RM) $(EXSV) $(EXCL)

re:	fclean $(EXSV) $(EXCL)

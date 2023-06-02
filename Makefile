# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 18:31:55 by feden-pe          #+#    #+#              #
#    Updated: 2023/06/01 19:05:24 by feden-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I$(HEADERS_DIRECTORY)

HEADERS_DIRECTORY = ./includes/
HEADERS_LIST = minitalk.h\

CL = client

SV = server

RM = rm -f

FT_PRINTF = ./ft_printf/libftprintf.a

LIBFT = ./libft/libft.a

SRCCL = client.c

SRCSV = server.c

all:	$(CL) $(SV)

$(CL):	$(LIBFT) $(FT_PRINTF) $(SRCCL)
	$(CC) $(CFLAGS) $(SRCCL) $(FT_PRINTF) $(LIBFT) $(INCLUDES) -o $(CL) -g

$(SV):	$(FT_PRINTF) $(SRCSV)
	$(CC) $(CFLAGS) $(SRCSV) $(FT_PRINTF) $(LIBFT) $(INCLUDES) -o $(SV) -g

$(LIBFT):
	make -C ./libft

$(FT_PRINTF):
	make -C ./ft_printf

clean:
	make clean -C ./libft
	make clean -C ./ft_printf
	$(RM)

fclean:	clean
	make fclean -C ./libft
	make fclean -C ./ft_printf
	$(RM) $(CL) $(SV)

re:	fclean $(CL) $(SV)

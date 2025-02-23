# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 16:26:45 by raljaber          #+#    #+#              #
#    Updated: 2024/05/27 19:21:56 by raljaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

all: client server

client: client.o $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) client.o $(FT_PRINTF_LIB) -o client  -I .

server: server.o $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) server.o $(FT_PRINTF_LIB) -o server -I .

bonus: client_bonus server_bonus

client_bonus: client_bonus.o $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) client_bonus.o $(FT_PRINTF_LIB) -o client_bonus -I .

server_bonus: server_bonus.o $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) server_bonus.o $(FT_PRINTF_LIB) -o server_bonus -I .

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	rm -f *.o

fclean: clean
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	rm -f client server client_bonus server_bonus

re: fclean all

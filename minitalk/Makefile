# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmassa-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 10:17:31 by mmassa-r          #+#    #+#              #
#    Updated: 2023/01/19 10:17:33 by mmassa-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GCC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(LIBFT):
		$(MAKE) -C ./libft

$(SERVER):	$(OBJ_SERVER) $(LIBFT)
		$(GCC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) -o server

$(CLIENT):	$(OBJ_CLIENT) $(LIBFT)
		$(GCC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) -o client

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(SERVER) $(CLIENT)

re:	fclean	all
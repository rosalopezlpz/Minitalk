# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlopez-l <rlopez-l@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 19:26:49 by rlopez-l          #+#    #+#              #
#    Updated: 2023/11/14 14:13:23 by rlopez-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~VARIABLES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
NAME = minitalk
CLIENT_NAME = client
SERVER_NAME = server
CC = gcc
RM = rm -rf
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror -g

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SORUCES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
CLIENT_SRC = client.c 
SERVER_SRC = server.c
LIB = ./minilib/
L_LIB = ./minilib/minilib.a
INC = -I minitalk.h\
	  -I ./minilib/\

OBJ_SERVER = $(SERVER_SRC:.c=.o)
OBJ_CLIENT = $(CLIENT_SRC:.c=.o)
DEP_SERVER = $(SERVER_SRC:.c=.d)
DEP_CLIENT = $(CLIENT_SRC:.c=.d)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAKE RULES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
all: dir
	$(MAKE) $(CLIENT_NAME) --no-print-directory
	$(MAKE) $(SERVER_NAME) --no-print-directory

dir:
	@make -C $(LIB) --no-print-directory

%.o: %.c
	@$(CC) -MMD $(FLAGS) -c $< -o $@ $(INC)

$(SERVER_NAME): $(OBJ_SERVER)
	@$(CC) $(FLAGS) $(OBJ_SERVER) $(L_LIB) -o $(SERVER_NAME) $(INC)
	@echo "$(SERVER_NAME) have been created."

$(CLIENT_NAME): $(OBJ_CLIENT)
	@$(CC) $(FLAGS) $(OBJ_CLIENT) $(L_LIB) -o $(CLIENT_NAME) $(INC)
	@echo "$(CLIENT_NAME) have been created."

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CLEAN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

fclean: clean
	$(RM) $(NAME) $(CLIENT_NAME) $(SERVER_NAME)
	@make fclean -C $(LIB) --no-print-directory
	@echo "Clean."

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(DEP_CLIENT) $(DEP_SERVER)
	@make clean -C $(LIB) --no-print-directory
	@echo "Clean."

re: fclean all

.PHONY:		all clean fclean re

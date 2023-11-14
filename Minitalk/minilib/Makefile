# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlopez-l <rlopez-l@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 12:15:44 by rlopez-l          #+#    #+#              #
#    Updated: 2023/11/14 13:49:45 by rlopez-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables

NAME = minilib.a
HEADER = minilib.h
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
INCLUDE = -I ./

SRC = ft_strlen.c ft_atoi.c ft_putnbr.c ft_putst.c

OBJ = $(SRC:.c=.o)

i%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@  

#rules

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar -rcs $(NAME) $?

.PHONY: clean fclean all re

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all


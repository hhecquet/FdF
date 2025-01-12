# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 11:47:31 by adelattr          #+#    #+#              #
#    Updated: 2025/01/06 12:22:02 by hhecquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = libftgnl.a

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRCS =	get_next_line.c 			\
		get_next_line_utils.c 				

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) get_next_line.h
	ar -rcs $(NAME) $(OBJ)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re

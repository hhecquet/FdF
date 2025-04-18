# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 11:44:52 by hhecquet          #+#    #+#              #
#    Updated: 2025/01/27 14:05:12 by hhecquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

R = \033[31m#Red
BR = \033[91m#Bright Red
O = \033[33m#Orange
Y = \033[93m#Yellow
BG = \033[92m#Bright Green
G = \033[32m#Green
BC = \033[96m#Bright Cyan
C = \033[36m#Cyan
BB = \033[94m#Bright Blue
B = \033[34m#Blue
BM = \033[95m#Bright Magenta
M = \033[35m#Magenta
RE = \033[0m#Reset
BO = \033[1m#Bold

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBS = -L minilibx-linux -lmlx -lXext -lX11 -lm

SRCS =	libft/*.c \
		libft/ft_printf/*.c \
		libft/get_next_line/*.c \
		srcs/main.c \
		srcs/parser.c \
		srcs/parser_utils.c \
		srcs/draw.c \
		srcs/rot.c \
		srcs/move.c \
		srcs/draw_utils.c \
		srcs/parallel.c
		
all: $(NAME)

bonus: $(NAME)

$(NAME): $(SRCS) includes/fdf.h
	cd libft && make -s
	cd ..
	echo "$(BO)$(R)B$(O)u$(Y)i$(BG)l$(G)d$(BC)i$(C)n$(BB)g $(B)M$(BM)i$(M)n$(R)i$(O)L$(Y)i$(BG)b$(G)X$(BC).$(C).$(BB).$(RE)"
	cd minilibx-linux && ./configure
	cd ..
	echo "Compiling FdF..."
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBS)
	echo "$(NAME) built $(R)su$(Y)cc$(G)es$(C)sf$(B)ul$(M)ly$(R)! 🌟$(RE)"
	echo "$(BR)          _____                    _____                    _____          "
	echo "         /\    \                  /\    \                  /\    \         "
	echo "        /::\    \                /::\    \                /::\    \        "
	echo "       /::::\    \              /::::\    \              /::::\    \       "
	echo "      /::::::\    \            /::::::\    \            /::::::\    \      "
	echo "     /:::/\:::\    \          /:::/\:::\    \          /:::/\:::\    \     "
	echo "    /:::/__\:::\    \        /:::/  \:::\    \        /:::/__\:::\    \    "
	echo "   /::::\   \:::\    \      /:::/    \:::\    \      /::::\   \:::\    \   "
	echo "  /::::::\   \:::\    \    /:::/    / \:::\    \    /::::::\   \:::\    \  "
	echo " /:::/\:::\   \:::\    \  /:::/    /   \:::\ ___\  /:::/\:::\   \:::\    \ "
	echo "/:::/  \:::\   \:::\____\/:::/____/     \:::|    |/:::/  \:::\   \:::\____\ "
	echo "\::/    \:::\   \::/    /\:::\    \     /:::|____|\::/    \:::\   \::/    / "
	echo " \/____/ \:::\   \/____/  \:::\    \   /:::/    /  \/____/ \:::\   \/____/  "
	echo "          \:::\    \       \:::\    \ /:::/    /            \:::\    \      "
	echo "           \:::\____\       \:::\    /:::/    /              \:::\____\     "
	echo "            \::/    /        \:::\  /:::/    /                \::/    /     "
	echo "             \/____/          \:::\/:::/    /                  \/____/      "
	echo "                               \::::::/    /                               "
	echo "                                \::::/    /                                "
	echo "                                 \::/____/                                 "

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes/fdf.h -Imlx_linux -O3 -c $< -o $

clean:
	cd libft && make -s clean
	cd ..
	cd minilibx-linux && ./configure clean
	cd ..
	echo "Cleaning FdF object files..."
	rm -f *.o
	echo "FdF object files have been cleaned 👌"

fclean: clean
	cd libft && make -s fclean
	cd ..
	cd minilibx-linux && ./configure clean
	cd ..
	rm -f $(NAME)
	echo "FdF itself has been cleaned 👌"

re: fclean all

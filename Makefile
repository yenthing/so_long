# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 20:33:08 by ynguyen           #+#    #+#              #
#    Updated: 2023/07/26 20:25:33 by ynguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX = minilibx-linux/libmlx.a
SRC = free.c image.c main.c map_sum.c map.c movement.c utils.c map_check.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

#%.o: %.c
    #$(CC) $(CFLAGS) -o $< -c $@ 
	
#.SILENT:

$(NAME): $(OBJ)
	echo "Let's play a game!"
	make -s -C minilibx-linux
	make -s -C Libft
	$(CC) $(OBJ) $(MLX) Libft/libft.a -o $(NAME) -lXext -lX11 
	echo "Are you ready to Play, huh?"

clean:
	echo "I deleted the o_files"
	make clean -s -C minilibx-linux
	make clean -s -C Libft
	rm -f $(OBJ)


fclean: clean 
	echo "and I deleted the game"
	rm -f Libft/libft.a
	rm -f so_long

re: fclean all

norm: 
	norminette *.c *.h

.PHONY: all clean fclean re norm

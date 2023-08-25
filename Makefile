# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 16:44:47 by ddyankov          #+#    #+#              #
#    Updated: 2023/08/23 16:03:04 by ddyankov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube3D

SRC = main.c init.c move.c render.c get_map.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

MLXFLAGS  = -I ./mlx -L ./mlx -lmlx -lXext -lX11 -lm

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@cc $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	
$(LIBFT):
	@make -C libft -s

$(MLX):
	@make -C mlx -s
	
clean:
	@rm -f $(OBJ)
	@make clean -C libft
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	
re: fclean all

.PHONY:		all clean fclean re

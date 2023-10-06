# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 16:44:47 by ddyankov          #+#    #+#              #
#    Updated: 2023/10/05 17:16:48 by ddyankov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED_BACK = \033[0;101m
GREEN_BACK = \033[0;102m
COLOUR_END = \033[0m

NAME = cub3D

SRC = main.c init.c move.c render.c get_map.c player.c key_events.c rays.c \
		rays_utils.c main_utils.c\
		map_check.c  map_check_walls.c map_manipulation.c\
		input_check_colors.c input_check_textures.c input_receiving.c\
		free.c move_directions.c textures.c

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

CFLAGS = -Wall -Werror -Wextra -MMD -MP -O3 -march=native

MLXFLAGS  = -I ./mlx -L ./mlx -lmlx -lXext -lX11 -lm

LIBFT = libft/libft.a

obj/%.o: %.c
		@mkdir -p obj
		@cc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@cc $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN_BACK)✅✅✅Executable $(NAME) is ready✅✅✅$(COLOUR_END)"
	
$(LIBFT):
	@make -C libft -s

$(MLX):
	@make -C mlx -s

test:
	./cub3D
	
clean:
	@rm -rf obj
	@make clean -C libft -s
	@echo "$(RED_BACK)🧹🧹🧹obj folder was cleaned🧹🧹🧹$(COLOUR_END)"
	
fclean: clean
	@rm -f $(NAME)	
	@make fclean -C libft -s
	@echo "$(RED_BACK)🧹🧹🧹Executable was cleaned🧹🧹🧹$(COLOUR_END)"

re: fclean all

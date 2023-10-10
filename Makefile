# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 16:44:47 by ddyankov          #+#    #+#              #
#    Updated: 2023/10/10 14:49:35 by ddyankov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED_BACK = \033[0;101m
GREEN_BACK = \033[0;102m
COLOUR_END = \033[0m

NAME = cub3D

BONUS_NAME = cub3D_bonus

SRC = main.c init.c move.c render.c player.c key_events.c rays.c \
		rays_utils.c main_utils.c\
		map_check.c  map_check_walls.c map_manipulation.c\
		input_check_colors.c input_check_colors_utils.c input_check_textures.c input_receiving.c\
		free.c free_and_error.c utils.c textures.c

BONUS_SRC_LIST = ${SRC:.c=_bonus.c}

BOUNS_SRC = ${BONUS_SRC_LIST}

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

BONUS_OBJ = $(patsubst %.c, obj/%.o, $(BOUNS_SRC))

CFLAGS = -Wall -Werror -Wextra -g -MMD -MP #-Ofast -march=native

MLXFLAGS  = -lmlx -lXext -lX11 -lm

LIBFT = libft/libft.a

obj/%.o: %.c
		@mkdir -p obj
		@cc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cc $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN_BACK)✅✅✅Executable $(NAME) is ready✅✅✅$(COLOUR_END)"

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT)
	@cc $(CFLAGS) $(BONUS_OBJ) $(MLXFLAGS) $(LIBFT) -o $(BONUS_NAME)
	@echo "$(GREEN_BACK)✅✅✅Executable $(BONUS_NAME) is ready✅✅✅$(COLOUR_END)"	

$(LIBFT):
	@make -C libft -s

bonus: $(BONUS_NAME)

clean:
	@rm -rf obj
	@make clean -C libft -s
	@echo "$(RED_BACK)🧹🧹🧹obj folder was cleaned🧹🧹🧹$(COLOUR_END)"
	
fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@make fclean -C libft -s
	@echo "$(RED_BACK)🧹🧹🧹Executable was cleaned🧹🧹🧹$(COLOUR_END)"

re: fclean all

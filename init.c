/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:55:34 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/05 17:23:36 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_player_init(t_game *game)
{
	game->player.dir_x = 0;
	game->player.dir_x = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.look_left = 0;
	game->player.look_right = 0;

}

void	ft_moves_init(t_game *game)
{
	game->moves.move_straight = 0;
	game->moves.move_side = 0;
	game->moves.rotate = 0;
}

void	ft_init(t_game *game)
{
	game->screen_width = 0;
	game->screen_height = 0;
	game->height = 0;
	game->width = 0;
	game->square_x = 0;
	game->square_y = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->lines = 0;
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->floor_color = NULL;
	game->ceiling_color = NULL;
	game->index = 0;
	game->all_done = 0;
	game->img.size = 0;
	ft_player_init(game);
	ft_moves_init(game);

}


void	ft_mlx_init(t_game *game)
{
	game->mlx = mlx_init();
	mlx_get_screen_size(game->mlx, &game->screen_width, &game->screen_height);
	game->win = mlx_new_window(game->mlx, game->screen_width,
			game->screen_height, "cub3D");
	game->img.mlx_img = mlx_new_image(game->mlx, game->screen_width,
			game->screen_height);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:55:34 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/09 17:13:48 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_player_moves_rays_init(t_game *game)
{
	game->player.x = 0;
	game->player.y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.look_left = 0;
	game->player.look_right = 0;
	game->player.fov = 0;
	game->moves.move_straight = 0;
	game->moves.move_side = 0;
	game->moves.rotate = 0;
	game->rays.ray_dir_x = 0;
	game->rays.ray_dir_y = 0;
	game->rays.delta_dist_x = 0;
	game->rays.delta_dist_y = 0;
	game->rays.side_dist_x = 0;
	game->rays.side_dist_y = 0;
	game->rays.wall_dist = 0;
	game->rays.side = 0;
	game->rays.step_x = 0;
	game->rays.step_y = 0;
}

static void	ft_init_help(t_game *game)
{
	game->screen_width = 0;
	game->screen_height = 0;
	game->width = 0;
	game->height = 0;
	game->square_x = 0;
	game->square_y = 0;
	game->lines = 0;
	game->index = 0;
	game->all_done = 0;
	game->start = 0;
	game->wall_height = 0;
	game->texture_x = 0;
	game->texture_y = 0;
	game->floor = 0;
	game->ceiling = 0;
	game->texture_current = 0;
	game->texture_move = 0;
	game->wall_coordinate = 0;
	game->north.size = 0;
	game->square_size = 12;
}

void	ft_init(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->file_name = NULL;
	game->content = NULL;
	game->tmp_string = NULL;
	game->no_texture = NULL;
	game->ea_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->floor_color = NULL;
	game->ceiling_color = NULL;
	game->img.mlx_img = NULL;
	game->img.addr = NULL;
	game->north.mlx_img = NULL;
	game->south.mlx_img = NULL;
	game->east.mlx_img = NULL;
	game->west.mlx_img = NULL;
	game->north.addr = NULL;
	game->south.addr = NULL;
	game->east.addr = NULL;
	game->west.addr = NULL;
	ft_init_help(game);
	ft_player_moves_rays_init(game);
}

void	ft_mlx_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_free_game(game, "MLX init failed", 1);
	mlx_get_screen_size(game->mlx, &game->screen_width, &game->screen_height);
	if (!game->screen_width || !game->screen_height)
		ft_free_game(game, "Screen Size is invalid", 1);
	game->win = mlx_new_window(game->mlx, game->screen_width,
			game->screen_height, "cub3D");
	if (!game->win)
		ft_free_game(game, "Creating new window failed", 1);
	game->img.mlx_img = mlx_new_image(game->mlx, game->screen_width,
			game->screen_height);
	if (!game->img.mlx_img)
		ft_free_game(game, "Creating new image failed", 1);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	if (!game->img.addr)
		ft_free_game(game, "Getting the img addres faield", 1);
}

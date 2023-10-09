/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:28:02 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/09 14:15:35 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_calc_distance(t_game *game)
{
	if (game->rays.side == 1)
		game->rays.wall_dist = game->rays.side_dist_y - game->rays.delta_dist_y;
	else
		game->rays.wall_dist = game->rays.side_dist_x - game->rays.delta_dist_x;
	if (game->rays.wall_dist <= 0)
		game->rays.wall_dist = 0.001;
}

static void	ft_check_if_wall(t_game *game)
{
	int	hit_wall;
	int	map_x;
	int	map_y;

	hit_wall = 0;
	map_x = (int)game->player.x;
	map_y = (int)game->player.y;
	while (!hit_wall)
	{
		if (game->rays.side_dist_x < game->rays.side_dist_y)
		{
			game->rays.side_dist_x += game->rays.delta_dist_x;
			map_x += game->rays.step_x;
			game->rays.side = 0;
		}
		else
		{
			game->rays.side_dist_y += game->rays.delta_dist_y;
			map_y += game->rays.step_y;
			game->rays.side = 1;
		}
		if (map_y < 0 || map_x < 0 || game->map[map_y][map_x] == '1')
			hit_wall = 1;
	}
}

static void	ft_calc_steps(t_game *game)
{
	float	diff_x;
	float	diff_y;

	diff_x = game->player.x - (int)game->player.x;
	diff_y = game->player.y - (int)game->player.y;
	if (game->rays.ray_dir_x < 0)
	{
		game->rays.step_x = -1;
		game->rays.side_dist_x = diff_x * game->rays.delta_dist_x;
	}
	else
	{
		game->rays.step_x = 1;
		game->rays.side_dist_x = (1 - diff_x) * game->rays.delta_dist_x;
	}
	if (game->rays.ray_dir_y < 0)
	{
		game->rays.step_y = -1;
		game->rays.side_dist_y = diff_y * game->rays.delta_dist_y;
	}
	else
	{
		game->rays.step_y = 1;
		game->rays.side_dist_y = (1 - diff_y) * game->rays.delta_dist_y;
	}
}

void	ft_calculate_wall(t_game *game)
{
	game->wall_height = (int)(game->screen_height / game->rays.wall_dist);
	game->start = -game->wall_height / 2 + game->screen_height / 2;
	if (game->start < 0)
		game->start = 0;
	if (game->rays.side)
		game->wall_coordinate = game->player.x + game->rays.wall_dist
			* game->rays.ray_dir_x;
	else
		game->wall_coordinate = game->player.y + game->rays.wall_dist
			* game->rays.ray_dir_y;
	game->wall_coordinate -= floor(game->wall_coordinate);
	game->texture_move = 1.0 * (float)game->north.size
		/ (float)game->wall_height;
	game->texture_x = (int)(game->wall_coordinate * (float)game->north.size);
	if ((game->rays.side == 0 && game->rays.ray_dir_x < 0)
		|| (game->rays.side == 1 && game->rays.ray_dir_y > 0))
		game->texture_x = game->north.size - game->texture_x - 1;
	game->texture_current = (game->start - game->screen_height / 2
			+ game->wall_height / 2) * game->texture_move;
}

void	ft_rays(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->screen_width)
	{
		game->player.fov = 2 * x / (float)game->screen_width - 1;
		game->rays.ray_dir_x = game->player.dir_x + (game->player.plane_x
				* game->player.fov);
		game->rays.ray_dir_y = game->player.dir_y + (game->player.plane_y
				* game->player.fov);
		if (game->rays.ray_dir_x == 0)
			game->rays.delta_dist_x = 10000000000;
		else
			game->rays.delta_dist_x = fabs(1.0 / game->rays.ray_dir_x);
		if (game->rays.ray_dir_y == 0)
			game->rays.delta_dist_y = 10000000000;
		else
			game->rays.delta_dist_y = fabs(1.0 / game->rays.ray_dir_y);
		ft_calc_steps(game);
		ft_check_if_wall(game);
		ft_calc_distance(game);
		ft_draw_textures(game, x);
		x++;
	}
}

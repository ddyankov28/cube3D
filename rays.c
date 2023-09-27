/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:28:02 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/27 12:48:07 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_horizontal_lines_angle(t_game *game)
{
	if (game->rays.angle > PI)
	{
		game->rays.y = (((int)game->player.y / SQUARE_SIZE) * SQUARE_SIZE)
			- 0.0001;
		game->rays.x = (game->player.y - game->rays.y) * game->rays.a_tan
			+ game->player.x;
		game->rays.y_offset = -SQUARE_SIZE;
		game->rays.x_offset = -game->rays.y_offset * game->rays.a_tan;
	}
	else if (game->rays.angle < PI)
	{
		game->rays.y = (((int)game->player.y / SQUARE_SIZE) * SQUARE_SIZE)
			+ SQUARE_SIZE;
		game->rays.x = (game->player.y - game->rays.y) * game->rays.a_tan
			+ game->player.x;
		game->rays.y_offset = SQUARE_SIZE;
		game->rays.x_offset = -game->rays.y_offset * game->rays.a_tan;
	}
	else if (game->rays.angle == 0 || game->rays.angle == PI)
	{
		game->rays.x = game->player.x;
		game->rays.y = game->player.y;
		game->rays.depth_of_field = 1000;
	}
}

void	ft_horizontal_lines_init(t_game *game)
{
	game->rays.distance_horizontal = 1000000;
	game->rays.horizont_x = game->player.x;
	game->rays.horizont_y = game->player.y;
	game->rays.depth_of_field = 0;
	game->rays.a_tan = -1 / tan(game->rays.angle);
}

void	ft_check_horizontal_lines(t_game *game)
{
	ft_horizontal_lines_init(game);
	ft_horizontal_lines_angle(game);
	while (game->rays.depth_of_field < 1000)
	{
		game->rays.map_x = (int)game->rays.x / SQUARE_SIZE;
		game->rays.map_y = (int)game->rays.y / SQUARE_SIZE;
		game->rays.map_pos = game->rays.map_y * game->width + game->rays.map_x;
		if (game->rays.map_pos > 0 && game->rays.map_pos < game->width
			* game->height && game->imap[game->rays.map_pos] == 1)
		{
			game->rays.horizont_x = game->rays.x;
			game->rays.horizont_y = game->rays.y;
			game->rays.distance_horizontal = ft_dist(game->player.x,
					game->player.y, game->rays.horizont_x,
					game->rays.horizont_y);
			game->rays.depth_of_field = 1000;
		}
		else
		{
			game->rays.x += game->rays.x_offset;
			game->rays.y += game->rays.y_offset;
			game->rays.depth_of_field++;
		}
	}
}

void	ft_vertical_lines_angle(t_game *game)
{
	if (game->rays.angle > P2 && game->rays.angle < P3)
	{
		game->rays.x = (((int)game->player.x / SQUARE_SIZE) * SQUARE_SIZE)
			- 0.0001;
		game->rays.y = (game->player.x - game->rays.x) * game->rays.n_tan
			+ game->player.y;
		game->rays.x_offset = -SQUARE_SIZE;
		game->rays.y_offset = -game->rays.x_offset * game->rays.n_tan;
	}
	else if (game->rays.angle < P2 || game->rays.angle > P3)
	{
		game->rays.x = (((int)game->player.x / SQUARE_SIZE) * SQUARE_SIZE)
			+ SQUARE_SIZE;
		game->rays.y = (game->player.x - game->rays.x) * game->rays.n_tan
			+ game->player.y;
		game->rays.x_offset = SQUARE_SIZE;
		game->rays.y_offset = -game->rays.x_offset * game->rays.n_tan;
	}
	else if (game->rays.angle == 0 || game->rays.angle == PI)
	{
		game->rays.x = game->player.x;
		game->rays.y = game->player.y;
		game->rays.depth_of_field = 1000;
	}
}

void	ft_vertical_lines_init(t_game *game)
{
	game->rays.distance_vertical = 1000000;
	game->rays.vertical_x = game->player.x;
	game->rays.vertical_y = game->player.y;
	game->rays.depth_of_field = 0;
	game->rays.n_tan = -tan(game->rays.angle);
}

void	ft_check_vertical_lines(t_game *game)
{
	ft_vertical_lines_init(game);
	ft_vertical_lines_angle(game);
	while (game->rays.depth_of_field < 1000)
	{
		game->rays.map_x = (int)game->rays.x / SQUARE_SIZE;
		game->rays.map_y = (int)game->rays.y / SQUARE_SIZE;
		game->rays.map_pos = game->rays.map_y * game->width + game->rays.map_x;
		if (game->rays.map_pos > 0 && game->rays.map_pos < game->width
			* game->height && game->imap[game->rays.map_pos] == 1)
		{
			game->rays.vertical_x = game->rays.x;
			game->rays.vertical_y = game->rays.y;
			game->rays.distance_vertical = ft_dist(game->player.x,
					game->player.y, game->rays.vertical_x,
					game->rays.vertical_y);
			game->rays.depth_of_field = 1000;
		}
		else
		{
			game->rays.x += game->rays.x_offset;
			game->rays.y += game->rays.y_offset;
			game->rays.depth_of_field++;
		}
	}
}

void	rays(t_game *game)
{
	game->scene.start_draw = 0;
	game->rays.angle = game->player.angle - DR * 30;
	ft_check_ray_angle(game);
	game->rays.ray = 0;
	while (game->rays.ray < 60)
	{
		ft_check_horizontal_lines(game);
		ft_check_vertical_lines(game);
		ft_rays_distance(game);
		ft_draw_line(game, game->player.x, game->player.y, game->rays.x,
			game->rays.y, GREEN);
		ft_draw_3d_scene(game);
		game->rays.angle += DR;
		ft_check_ray_angle(game);
		game->rays.ray++;
	}
}

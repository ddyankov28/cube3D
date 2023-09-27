/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:16:35 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/27 12:48:51 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_check_ray_angle(t_game *game)
{
	if (game->rays.angle < 0)
		game->rays.angle += 2 * PI;
	if (game->rays.angle > 2 * PI)
		game->rays.angle -= 2 * PI;
}

void	ft_rays_distance(t_game *game)
{
	if (game->rays.distance_vertical < game->rays.distance_horizontal)
	{
		game->rays.x = game->rays.vertical_x;
		game->rays.y = game->rays.vertical_y;
		game->scene.distance = game->rays.distance_vertical;
	}
	else if (game->rays.distance_horizontal < game->rays.distance_vertical)
	{
		game->rays.x = game->rays.horizont_x;
		game->rays.y = game->rays.horizont_y;
		game->scene.distance = game->rays.distance_horizontal;
	}
}

void	ft_draw_3d_scene(t_game *game)
{
	int	how_often;
	int	x;

	game->scene.cos_angle = game->player.angle - game->rays.angle;
	if (game->scene.cos_angle < 0)
		game->scene.cos_angle += 2 * PI;
	if (game->scene.cos_angle > 2 * PI)
		game->scene.cos_angle -= 2 * PI;
	game->scene.distance = game->scene.distance * cos(game->scene.cos_angle);
	game->scene.line_height = SQUARE_SIZE * game->screen_height
		/ game->scene.distance;
	if (game->scene.line_height > game->screen_height)
		game->scene.line_height = game->screen_height;
	game->scene.line_offset = game->screen_height / 2 - game->scene.line_height
		/ 2;
	how_often = game->screen_width / 60;
	x = 0;
	while (x < how_often)
	{
		ft_draw_line(game, game->scene.start_draw + x, game->scene.line_offset,
			game->scene.start_draw + x, game->scene.line_height
			+ game->scene.line_offset, GREEN);
		x++;
	}
	game->scene.start_draw += how_often;
}

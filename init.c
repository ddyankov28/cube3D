/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:55:34 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/25 17:28:02 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    ft_init(t_game *game)
{
    game->screen_width = 0;
    game->screen_height = 0;
    game->height = 0;
    game->width = 0;
    game->square_x = 0;
	game->square_y = 0;
    game->player.x = 0;
	game->player.y = 0;
    game->mlx = mlx_init();
    game->map = malloc(10000);
    game->scene.distance = 0;
    game->scene.line_height = 0;
    
}

void    ft_events_init(t_game *game)
{
    game->moves.move_back = 0;
    game->moves.move_forward = 0;
    game->moves.move_left = 0;
    game->moves.move_right = 0;
    game->moves.rotate_left = 0;
    game->moves.rotate_right = 0;
}

void    ft_rays_init(t_game *game)
{
    game->rays.ray = 0;
    game->rays.depth_of_field = 0;
    game->rays.map_x = 0;
    game->rays.map_y = 0;
    game->rays.map_pos = 0;
    game->rays.x = 0;
    game->rays.y = 0;
    game->rays.angle = 0;
    game->rays.x_offset = 0;
    game->rays.y_offset = 0;
    game->rays.a_tan = 0;
    game->rays.n_tan = 0;
    game->rays.horizont_x = 0;
    game->rays.horizont_y = 0;
    game->rays.vertical_x = 0;
    game->rays.vertical_y = 0;
    game->rays.distance_horizontal = 0;
    game->rays.distance_vertical = 0;
}

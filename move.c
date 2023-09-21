/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:56:42 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/21 13:50:28 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool    ft_player_in_bounds(t_game *game)
{
    if (game->player.x < 0 || game->player.y < 0 || game->player.x > game->screen_width || game->player.y > game->screen_height)
        return false;
    return true;
}

void    ft_move_forward(t_game *game)
{
    game->player.x += game->player.delta_x / 5;
    game->player.y += game->player.delta_y / 5;
    if (!ft_player_in_bounds(game))
    {
        game->player.x -= game->player.delta_x / 5;
        game->player.y -= game->player.delta_y / 5;
    }
}
void    ft_move_back(t_game *game)
{
    game->player.x -= game->player.delta_x / 5;
    game->player.y -= game->player.delta_y / 5;
    if (!ft_player_in_bounds(game))
    {
        game->player.x += game->player.delta_x / 5;
        game->player.y += game->player.delta_y / 5;
    }
}

void    ft_move_right(t_game *game)
{
    game->player.x -= cos(game->player.angle - (PI / 2));
    game->player.y -= sin(game->player.angle - (PI / 2));
    if (!ft_player_in_bounds(game))
    {
        game->player.x += cos(game->player.angle - (PI / 2));
        game->player.y += sin(game->player.angle - (PI / 2));
    }
}
void    ft_move_left(t_game *game)
{
    game->player.x += cos(game->player.angle + (3 * PI / 2));
    game->player.y += sin(game->player.angle + (3 * PI / 2));
    if (!ft_player_in_bounds(game))
    {
        game->player.x -= cos(game->player.angle - (PI / 2));
        game->player.y -= sin(game->player.angle - (PI / 2));
    }
}

void    ft_rotate_right(t_game *game)
{
    game->player.angle += ANGLE_SPEED;
    if (game->player.angle > 2 * PI)
        game->player.angle -= 2 * PI;
    game->player.delta_x = cos(game->player.angle) * 5;
    game->player.delta_y = sin(game->player.angle) * 5;
}

void    ft_rotate_left(t_game *game)
{
    game->player.angle -= ANGLE_SPEED;
    if (game->player.angle < 0)
        game->player.angle += 2 * PI;
    game->player.delta_x = cos(game->player.angle) * 5;
    game->player.delta_y = sin(game->player.angle) * 5;
}
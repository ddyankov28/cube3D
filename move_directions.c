/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:01:51 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/05 14:40:45 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"
void    ft_straight_or_back(t_game *game, int direction)
{
    float   speed_x;
    float   speed_y;
    int     next_x;
    int     next_y;
    
    speed_x = game->moves.walk_speed * game->player.dir_x;
    speed_y = game->moves.walk_speed * game->player.dir_y;
    if (direction == 2)
    {
        speed_x = -game->moves.walk_speed * game->player.dir_x;
        speed_y = -game->moves.walk_speed * game->player.dir_y;
    }
    next_x = (int)(game->player.x + speed_x);
    next_y = (int)(game->player.y + speed_y);
    if (next_x < game->width && next_y < game->height && 
        game->imap[next_y][next_x] == 0)
    {
        // if (next_x != (int)game->player.x || next_y != (int)game->player.y)
        //     return ;
        game->player.x += speed_x;
        game->player.y += speed_y;
    }
}
void    ft_left_or_right(t_game *game, int direction)
{
    float   speed_x;
    float   speed_y;
    int     next_x;
    int     next_y;
    float   angle;

    angle = 3 * PI / 2;
    if (direction == 2)
        angle = PI / 2;
    game->player.look_left = game->player.dir_x * cos(angle) - game->player.dir_y * sin(angle);
    game->player.look_right = game->player.dir_x * sin(angle) - game->player.dir_y * cos(angle);
    speed_x = game->moves.walk_speed * game->player.look_left;
    speed_y = game->moves.walk_speed * game->player.look_right;
    next_x = (int)(game->player.x + speed_x);
    next_y = (int)(game->player.y + speed_y);
    if (next_x < game->width && next_y < game->height
        && game->imap[next_y][next_x] == 0)
    {
        // if (next_x != (int)game->player.x || next_y != (int)game->player.y)
        //     return ;
        game->player.x += speed_x;
        game->player.y += speed_y;
    }
}

void    ft_rotate(t_game *game, float angle)
{
    float   tmp_x;
    float   tmp_y;

	tmp_x = game->player.dir_x * cos(angle) + game->player.dir_y * sin(angle);
	tmp_y = game->player.dir_x * -sin(angle) + game->player.dir_y * cos(angle);
	game->player.dir_x = tmp_x;
	game->player.dir_y = tmp_y;
    tmp_x = game->player.plane_x * cos(angle) + game->player.plane_y * sin(angle);
	tmp_y = game->player.plane_x * -sin(angle) + game->player.plane_y * cos(angle);
	game->player.plane_x = tmp_x;
	game->player.plane_y = tmp_y;
}

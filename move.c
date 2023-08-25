/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:56:42 by ddyankov          #+#    #+#             */
/*   Updated: 2023/08/25 12:32:37 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_key_press(int key, t_game *game)
{
	printf("%d\n", key);
	if (key == ESCAPE)
		exit(0);
	if (key == W)
    {
        game->player.x += game->player.delta_x;
        game->player.y += game->player.delta_y;
    }
	if (key == S)
    {
        game->player.x -= game->player.delta_x;
        game->player.y -= game->player.delta_y;
    }
	if (key == A)
    {
        game->player.angle -= 0.1;
        if (game->player.angle < 0)
            game->player.angle += 2 * PI;
        game->player.delta_x = cos(game->player.angle) * 10;
        game->player.delta_y = sin(game->player.angle) * 10;
    }
	if (key == D)
    {
        game->player.angle += 0.1;
        if (game->player.angle > 2 * PI)
            game->player.angle -= 2 * PI;
        game->player.delta_x = cos(game->player.angle) * 10;
        game->player.delta_y = sin(game->player.angle) * 10;
    }
	return (0);
}

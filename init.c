/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:55:34 by ddyankov          #+#    #+#             */
/*   Updated: 2023/08/24 14:49:23 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    ft_init(t_game *game)
{
    game->height = 0;
    game->width = 0;
    game->square_x = 0;
	game->square_y = 0;
    game->player.x = 60;
	game->player.y = 60;
    game->player.delta_x = cos(game->player.angle) * 10;
    game->player.delta_y = sin(game->player.angle) * 10;
    game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cube3D");
    game->map = malloc(10000);
}
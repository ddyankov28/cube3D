/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:43:17 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/04 17:06:11 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_find_player_position(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->height)
	{
		game->square_x = 0;
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == 'E' || game->map[y][x] == 'N'
				|| game->map[y][x] == 'S' || game->map[y][x] == 'W')
			{
				game->player.x = x + 0.5;
				game->player.y = y + 0.5;
			}
		}
	}
}

void	ft_player_angle(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == 'E')
			{
				game->player.plane_y = 0.66;
				game->player.dir_x = 1;
			}
			else if (game->map[y][x] == 'S')
			{
				game->player.plane_x =-0.66;
				game->player.dir_y = 1;
			}
			else if (game->map[y][x] == 'N')
			{
				game->player.plane_x = 0.66;
				game->player.dir_y = -1;
			}
			else if (game->map[y][x] == 'W')
			{
				game->player.plane_y = -0.66;
				game->player.dir_x = -1;
			}
		}
	}
}

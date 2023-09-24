/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:43:17 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/24 21:03:16 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"

void	ft_find_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		game->square_x = 0;
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'E' || game->map[y][x] == 'N' || game->map[y][x] == 'S' || game->map[y][x] == 'W') 
			{
				game->player.x = game->square_x + SQUARE_SIZE / 2;
				game->player.y = game->square_y + SQUARE_SIZE / 2;
			}
			game->square_x += SQUARE_SIZE;
			x++;
		}
		y++;
		game->square_y += SQUARE_SIZE;
	}
}
void    ft_player_angle(t_game *game)
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
                game->player.angle = 0;
            else if (game->map[y][x] == 'S')
                game->player.angle = PI / 2;
            else if (game->map[y][x] == 'N')
                game->player.angle = (3 * PI) / 2;
            else if (game->map[y][x] == 'W')
                game->player.angle = PI;
        }
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:56:42 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/05 14:40:45 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	ft_player_in_bounds(t_game *game)
{
	if (game->player.x < 0 || game->player.y < 0 || game->player.x > SQUARE_SIZE
		* game->width || game->player.y > SQUARE_SIZE * game->height)
		return (false);
	return (true);
}

void	ft_move(t_game *game)
{
	if (game->moves.move_straight == 1)
		ft_straight_or_back(game, 1);
	else if (game->moves.move_straight == 2)
		ft_straight_or_back(game, 2);
	if (game->moves.move_side == 1)
		ft_left_or_right(game, 1);
	else if (game->moves.move_side == 2)
		ft_left_or_right(game, 2);
	if (game->moves.rotate == 1)
		ft_rotate(game, game->moves.rotation_speed);
	else if (game->moves.rotate == 2)
		ft_rotate(game, -game->moves.rotation_speed);
}

void	ft_calculate_speed(t_game *game)
{
	game->moves.frame_time = 1 / TARGET_FPS;
	if (game->moves.prev_time == 0)
		game->moves.prev_time = clock();
	game->moves.difference = (float)(clock() - game->moves.prev_time) / CLOCKS_PER_SEC;
	game->moves.prev_time = clock();
	if (TARGET_FPS && game->moves.difference < game->moves.frame_time)
	{
		game->moves.start_time = clock();
		game->moves.time_passed = game->moves.frame_time - game->moves.difference;
		while ((float)(clock()- game->moves.start_time) / CLOCKS_PER_SEC < game->moves.time_passed)
			;
		game->moves.difference = game->moves.frame_time;
	}
	game->moves.walk_speed = game->moves.difference * WALK_SPEED_RATIO;
	game->moves.rotation_speed = game->moves.difference * ROT_SPEED_RATIO;
}

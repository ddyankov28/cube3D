/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:56:42 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/06 10:04:31 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
		ft_rotate(game, ROTATE_SPEED);
	else if (game->moves.rotate == 2)
		ft_rotate(game, -ROTATE_SPEED);
}

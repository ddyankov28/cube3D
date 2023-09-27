/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:11:38 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/26 13:43:05 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_update_game(t_game *game)
{
	if (game->moves.move_forward)
		ft_move_forward(game);
	if (game->moves.move_back)
		ft_move_back(game);
	if (game->moves.move_left)
		ft_move_left(game);
	if (game->moves.move_right)
		ft_move_right(game);
	if (game->moves.rotate_left)
		ft_rotate_left(game);
	if (game->moves.rotate_right)
		ft_rotate_right(game);
}

int	ft_key_press(int key, t_game *game)
{
	printf("%d\n", key);
	if (key == XK_Escape)
		exit(0);
	if (key == XK_w)
		game->moves.move_forward = 1;
	if (key == XK_s)
		game->moves.move_back = 1;
	if (key == XK_d)
		game->moves.move_right = 1;
	if (key == XK_a)
		game->moves.move_left = 1;
	if (key == XK_Left)
		game->moves.rotate_left = 1;
	if (key == XK_Right)
		game->moves.rotate_right = 1;
	ft_update_game(game);
	return (0);
}

int	ft_key_release(int key, t_game *game)
{
	if (key == XK_w)
		game->moves.move_forward = 0;
	if (key == XK_s)
		game->moves.move_back = 0;
	if (key == XK_d)
		game->moves.move_right = 0;
	if (key == XK_a)
		game->moves.move_left = 0;
	if (key == XK_Left)
		game->moves.rotate_left = 0;
	if (key == XK_Right)
		game->moves.rotate_right = 0;
	ft_update_game(game);
	return (0);
}

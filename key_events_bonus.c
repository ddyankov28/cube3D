/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:11:38 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/10 14:33:47 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

int	ft_key_press(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		mlx_destroy_image(game->mlx, game->north.mlx_img);
		mlx_destroy_image(game->mlx, game->east.mlx_img);
		mlx_destroy_image(game->mlx, game->west.mlx_img);
		mlx_destroy_image(game->mlx, game->south.mlx_img);
		ft_free_game(game, NULL, 0);
	}
	else if (key == XK_w)
		game->moves.move_straight = 1;
	else if (key == XK_s)
		game->moves.move_straight = 2;
	else if (key == XK_a)
		game->moves.move_side = 1;
	else if (key == XK_d)
		game->moves.move_side = 2;
	else if (key == XK_Left)
		game->moves.rotate = 1;
	else if (key == XK_Right)
		game->moves.rotate = 2;
	return (0);
}

int	ft_key_release(int key, t_game *game)
{
	if (key == XK_w)
		game->moves.move_straight = 0;
	if (key == XK_s)
		game->moves.move_straight = 0;
	if (key == XK_a)
		game->moves.move_side = 0;
	if (key == XK_d)
		game->moves.move_side = 0;
	if (key == XK_Left)
		game->moves.rotate = 0;
	if (key == XK_Right)
		game->moves.rotate = 0;
	return (0);
}

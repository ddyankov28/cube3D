/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:56:42 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/10 14:33:47 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

/* calculates new coordinates for a player's movement based on their current
direction. It then checks if the new position is valid on the game map,
considering specific map characters. If the new position is valid, it updates
the player's coordinates for movement; otherwise, it prevents the movement.*/

static void	ft_straight_or_back(t_game *game, int direction)
{
	float	speed_x;
	float	speed_y;
	int		next_x;
	int		next_y;

	speed_x = MOVE_SPEED * game->player.dir_x;
	speed_y = MOVE_SPEED * game->player.dir_y;
	if (direction == 2)
	{
		speed_x = -MOVE_SPEED * game->player.dir_x;
		speed_y = -MOVE_SPEED * game->player.dir_y;
	}
	next_x = (int)(game->player.x + speed_x);
	next_y = (int)(game->player.y + speed_y);
	if (game->map[next_y][next_x] == '0' || game->map[next_y][next_x] == 'N'
		|| game->map[next_y][next_x] == 'E' || game->map[next_y][next_x] == 'S'
		|| game->map[next_y][next_x] == 'W')
	{
		game->player.x += speed_x;
		game->player.y += speed_y;
	}
}

/* handles player movement to the left or right based on the direction input.
It calculates new coordinates for the player's position by rotating their
direction vector by a specific angle (either 90 or 270 degrees).
Then, it computes the movement speed components along the new directions,
checks if the next position is valid on the game map, and updates the player's
coordinates accordingly if it's a valid move. */

static void	ft_left_or_right(t_game *game, int direction)
{
	float	speed_x;
	float	speed_y;
	int		next_x;
	int		next_y;
	float	angle;

	angle = DEGR_270;
	if (direction == 2)
		angle = DEGR_90;
	game->player.look_left = game->player.dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.look_right = game->player.dir_x * sin(angle)
		- game->player.dir_y * cos(angle);
	speed_x = MOVE_SPEED * game->player.look_left;
	speed_y = MOVE_SPEED * game->player.look_right;
	next_x = (int)(game->player.x + speed_x);
	next_y = (int)(game->player.y + speed_y);
	if (game->map[next_y][next_x] == '0' || game->map[next_y][next_x] == 'N'
		|| game->map[next_y][next_x] == 'E' || game->map[next_y][next_x] == 'S'
		|| game->map[next_y][next_x] == 'W')
	{
		game->player.x += speed_x;
		game->player.y += speed_y;
	}
}

/* Rotating the player's direction and plane vectors by a specified angle.
It uses trigonometric calculations to update the direction and plane vectors,
effectively changing the player's viewing direction and the plane that defines
their field of view. */

static void	ft_rotate(t_game *game, float angle)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = game->player.dir_x * cos(angle) + game->player.dir_y * sin(angle);
	tmp_y = game->player.dir_x * -sin(angle) + game->player.dir_y * cos(angle);
	game->player.dir_x = tmp_x;
	game->player.dir_y = tmp_y;
	tmp_x = game->player.plane_x * cos(angle) + game->player.plane_y
		* sin(angle);
	tmp_y = game->player.plane_x * -sin(angle) + game->player.plane_y
		* cos(angle);
	game->player.plane_x = tmp_x;
	game->player.plane_y = tmp_y;
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
		ft_rotate(game, ROTATE_SPEED);
	else if (game->moves.rotate == 2)
		ft_rotate(game, -ROTATE_SPEED);
}

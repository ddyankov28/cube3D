/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:50:45 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/09 13:05:04 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_2d_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->square_x = 0;
	game->square_y = 0;
	while (++y < game->height)
	{
		game->square_x = 0;
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == '1')
				ft_draw_square(game, BLUE);
			else if (game->map[y][x] == '0')
				ft_draw_square(game, RED);
			else if (game->map[y][x] == 'E' || game->map[y][x] == 'N'
				|| game->map[y][x] == 'W' || game->map[y][x] == 'S')
				ft_draw_square(game, RED);
			game->square_x += SQUARE_SIZE;
		}
		game->square_y += SQUARE_SIZE;
	}
}

void	ft_draw_square(t_game *game, int color)
{
	int	x;
	int	y;

	x = -1;
	y = 0;
	while (++x < SQUARE_SIZE)
	{
		y = -1;
		while (++y < SQUARE_SIZE)
			img_pix_put(game, game->square_x + x, game->square_y + y, color);
	}
}

void	ft_draw_background(t_game *game)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	color = game->ceiling;
	while (++i < game->screen_height)
	{
		j = -1;
		if (color == game->ceiling && i >= game->screen_height / 2)
			color = game->floor;
		while (++j < game->screen_width)
			img_pix_put(game, j, i, color);
	}
}

void	img_pix_put(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < game->screen_width && y >= 0 && y < game->screen_height)
	{
		pixel = game->img.addr + (y * game->img.line_len + x * (game->img.bpp
					/ 8));
		*(int *)pixel = color;
	}
}

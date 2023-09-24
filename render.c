/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:50:45 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/24 21:04:40 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_2d_map(t_game *game)
{
	int x, y = 0;
	game->square_x = 0;
	game->square_y = 0;
	while (y < game->height)
	{
		game->square_x = 0;
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				ft_draw_square(game, BLUE);	
			else if (game->map[y][x] == '0')
				ft_draw_square(game, RED);
			else if (game->map[y][x] == 'E' || game->map[y][x] == 'N' || game->map[y][x] == 'W' || game->map[y][x] == 'S')
				ft_draw_square(game, BLACK);
			game->square_x += SQUARE_SIZE - 1;
			x++;
		}
		y++;
		game->square_y += SQUARE_SIZE;
	}
}
void	ft_draw_circle(t_game *game)
{
	float i, angle, x1, y1;
	for (i = 0; i < 360; i += 0.1)
	{
		angle = i;
		x1 = PLAYER_SIZE * cos(angle * PI / 180);
      	y1 = PLAYER_SIZE * sin(angle * PI / 180);
		img_pix_put(game, game->player.x + x1, game->player.y + y1, GREEN);
	}
}
void	ft_draw_square(t_game *game, int color)
{
	int x = 0;
	int y;
	
	while (++x < SQUARE_SIZE)
	{
		y = -1;
		while (++y < SQUARE_SIZE)
			img_pix_put(game, game->square_x + x, game->square_y + y , color);
	}

}
void    ft_draw_background(t_game *game)
{
    int	i;
    int	j;

    i = -1;
    while (++i < game->screen_height)
    {
        j = -1;
        while (++j < game->screen_width)
	   	img_pix_put(game, j, i, GREY);
    }
}

void	img_pix_put(t_game *game, int x, int y, int color)
{
	
	char	*pixel;
	
	if (x >= 0 && x <  game->screen_width && y >= 0 && y < game->screen_height)
	{
		pixel = game->img.addr + (y * game->img.line_len + x * (game->img.bpp / 8));
		*(int *)pixel = color;
	}
}

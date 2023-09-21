/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:50:45 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/21 13:47:09 by ddyankov         ###   ########.fr       */
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
			game->square_x += SQUARE_SIZE + 1;
			x++;
		}
		y++;
		game->square_y += SQUARE_SIZE + 1;
	}
}

void	ft_draw_player(t_game *game)
{
	int x = 0;
	int y = 0;
	while (x < PLAYER_SIZE)
	{
		y = 0;
		while (y < PLAYER_SIZE)
		{
			if (!img_pix_put(game, game->player.x + x, game->player.y + y, GREEN))
				return ;
			y++;
		}
		x++;
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
		if (!img_pix_put(game, game->player.x + x1, game->player.y + y1, GREEN))
				return ;
	}
}
void	ft_draw_square(t_game *game, int color)
{
	int x = 0;
	int y = 0;
	
	while (x < SQUARE_SIZE)
	{
		y = 0;
		while (y < SQUARE_SIZE)
		{
			if (!img_pix_put(game, game->square_x + x, game->square_y + y , color))
				return ;
			y++;
		}
		x++;
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
        {
            if (!img_pix_put(game, j, i, GREY))
				return ;
        }
    }
}

void	ft_draw_line(t_game *game, int player_x, int player_y, int x2, int y2)
{
	int dx = x2 - player_x;
	int dy = y2 - player_y;
	int	steps;
	
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	float x_i = (float)dx / steps;
	float y_i = (float)dy / steps;
	float x = (float)player_x;
	float y = (float)player_y;

	int i = 0;
	while (i <= steps)
	{
		if (!img_pix_put(game, (int)x, (int)y, YELLOW))
			return ;
		x += x_i;
		y += y_i;
		i++;
	}
}

int	img_pix_put(t_game *game, int x, int y, int color)
{
	
	char	*pixel;
	int 	i;
	
	if (x >= 0 && x <  game->screen_width && y >= 0 && y < game->screen_height)
	{
		i = game->img.bpp - 8;
		pixel = game->img.addr + (y * game->img.line_len + x * (game->img.bpp / 8));
		while (i >= 0)
		{
			if (game->img.endian != 0)
				*pixel++ = (color >> i) & 0xFF;
			else
				*pixel++ = (color >> (game->img.bpp - 8 - i)) & 0xFF;
			i -= 8;
		}
	}
	else
		return (0);
	return (1);
}

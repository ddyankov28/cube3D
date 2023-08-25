/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:50:45 by ddyankov          #+#    #+#             */
/*   Updated: 2023/08/25 13:05:07 by ddyankov         ###   ########.fr       */
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
			if (game->int_map[y][x] == 1)
				ft_draw_square(game, BLUE);		
			else if (game->int_map[y][x] == 0)
				ft_draw_square(game, RED);
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
			if (!img_pix_put(&game->img, game->player.x + x, game->player.y + y, GREEN))
				return ;
			y++;
		}
		x++;
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
			if (!img_pix_put(&game->img, game->square_x + x, game->square_y + y, color))
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

    i = 0;
    while (i < HEIGHT)
    {
        j = 0;
        while (j < WIDTH)
        {
            if (!img_pix_put(&game->img, j++, i, GREY))
				return ;
        }
        ++i;
    }
}

void	ft_draw_line(t_game *game, int x1, int y1, int x2, int y2, int color)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int	steps;
	
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	float x_i = (float)dx / steps;
	float y_i = (float)dy / steps;
	float x = (float)x1;
	float y = (float)y1;

	int i = 0;
	while (i <= steps)
	{
		if (!img_pix_put(&game->img, (int)x + PLAYER_SIZE / 2, (int)y + PLAYER_SIZE / 2, color))
			return ;
		x += x_i;
		y += y_i;
		i++;
	}
}

int	img_pix_put(t_img *img, int x, int y, int color)
{
	
	char	*pixel;
	int 	i;
	
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = img->bpp - 8;
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		while (i >= 0)
		{
			if (img->endian != 0)
				*pixel++ = (color >> i) & 0xFF;
			else
				*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
			i -= 8;
		}
	}
	else{
		printf("something bad is happening\n\n");
		return (0);
	}
	return (1);
}

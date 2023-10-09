/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:16:35 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/09 14:08:45 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_draw_walls(t_game *game, int x, int y, int texture)
{
	int	color;

	color = 0;
	if (texture == 1)
		color = (*(int *)(game->north.addr + (game->texture_y
						* game->north.line_len + game->texture_x
						* (game->north.bpp
							/ 8))));
	else if (texture == 2)
		color = (*(int *)(game->south.addr + (game->texture_y
						* game->south.line_len + game->texture_x
						* (game->south.bpp
							/ 8))));
	else if (texture == 3)
		color = (*(int *)(game->east.addr + (game->texture_y
						* game->east.line_len + game->texture_x
						* (game->east.bpp
							/ 8))));
	else if (texture == 4)
		color = (*(int *)(game->west.addr + (game->texture_y
						* game->west.line_len + game->texture_x
						* (game->west.bpp
							/ 8))));
	img_pix_put(game, x, y, color);
}

void	ft_draw_textures(t_game *game, int x)
{
	int	end;

	ft_calculate_wall(game);
	end = game->wall_height / 2 + game->screen_height / 2;
	if (end >= game->screen_height)
		end = game->screen_height - 1;
	while (game->start <= end)
	{
		game->texture_y = (int)game->texture_current % game->north.size;
		game->texture_current += game->texture_move;
		if (game->rays.side == 0 && game->rays.ray_dir_x < 0)
			ft_draw_walls(game, x, game->start, 4);
		else if (game->rays.side == 0 && game->rays.ray_dir_x > 0)
			ft_draw_walls(game, x, game->start, 3);
		else if (game->rays.side == 1 && game->rays.ray_dir_y < 0)
			ft_draw_walls(game, x, game->start, 1);
		else if (game->rays.side == 1 && game->rays.ray_dir_y > 0)
			ft_draw_walls(game, x, game->start, 2);
		game->start++;
	}
}

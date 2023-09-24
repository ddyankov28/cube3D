/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:49:32 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/24 21:15:02 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_close_x()
{
	exit(0);
}

void	draw_line(t_game *game, int beginX, int beginY, int endX, int endY)
{
	double deltaX = endX - beginX;
	double deltaY = endY - beginY;

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
    		img_pix_put(game, pixelX, pixelY, GREEN);
    		pixelX += deltaX;
    		pixelY += deltaY;
    		--pixels;
	}
}

int	render(t_game *game)
{
	ft_draw_background(game);
	ft_draw_2d_map(game);
	ft_draw_circle(game);
	draw_line(game, game->player.x, game->player.y, game->player.x + game->player.delta_x, game->player.y + game->player.delta_y);
	mlx_put_image_to_window(game->mlx, game->win, game->img.mlx_img, 0, 0);
	return 0;
}

void	print_map(t_game *game)
{
	printf("Converted Integer Array:\n");
    for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->width; j++) {
            printf("%c ", game->map[i][j]);
        }
        printf("\n");
    }
	printf("MAP WIDTH %d\nMAP HEIGHT %d\n", game->width, game->height);
}


int	main()
{
	t_game	game;
	
	ft_init(&game);
	ft_events_init(&game);
	ft_get_map(&game, "map.txt");
	ft_find_player_position(&game);
	ft_player_angle(&game);
	mlx_get_screen_size(game.mlx, &game.screen_width, &game.screen_height);
	game.win = mlx_new_window(game.mlx, game.screen_width, game.screen_height, "cub3D");
	game.player.delta_x = cos(game.player.angle) * 5;
     game.player.delta_y = sin(game.player.angle) * 5;
	print_map(&game);
	game.img.mlx_img = mlx_new_image(game.mlx, game.screen_width, game.screen_height);
	game.img.addr = mlx_get_data_addr(game.img.mlx_img, &game.img.bpp,
			&game.img.line_len, &game.img.endian);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game);
	mlx_hook(game.win, 17, 1L << 17, ft_close_x, &game);
	mlx_loop(game.mlx);
	return (0);
}

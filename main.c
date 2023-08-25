/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:49:32 by ddyankov          #+#    #+#             */
/*   Updated: 2023/08/25 13:04:07 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_close_x()
{
	exit(0);
}

void	draw_rays(t_game *game)
{
	int ray = 0, mx = 0, my = 0, mp = 0, depth_of_field = 0;
	float rx = 0, ry = 0, ray_angle = 0, xo = 0, yo = 0;
	ray_angle = game->player.angle;
	for (ray = 0;ray < 1; ray++)
	{
		// Check Horizontal Lines
		depth_of_field = 0;
		float aTan = -1 / tan(ray_angle);
		if (ray_angle > PI)
		{
			ry = (((int)game->player.y >> 6) << 6) - 0.0001; //looking up
			rx = (game->player.y - ry) * aTan + game->player.x;
			yo = -64;
			xo = -yo * aTan; 
		}
		if (ray_angle < PI)
		{
			ry = (((int)game->player.y >> 6) << 6) + 64; //looking up
			rx = (game->player.y - ry) * aTan + game->player.x;
			yo = 64;
			xo = -yo * aTan; 
		}
		if (ray_angle == 0 || ray_angle == PI)
		{
			rx = game->player.x;
			ry = game->player.y;
			depth_of_field = 8;
		}
		while (depth_of_field < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * game->width + mx;
			if (mp < game->width * game->height && game->int_map[my][mx] == 1)
			{
				depth_of_field = 8;
				break ;
			}
			else
			{
				rx += xo;
				ry += yo;
				depth_of_field += 1;
			}	
		}
		ft_draw_line(game, game->player.x, game->player.y, rx, ry, GREEN);
	}
}

int	render(t_game *game)
{
	ft_draw_background(game);
	ft_draw_2d_map(game);
	ft_draw_player(game);
	ft_draw_line(game, game->player.x, game->player.y, game->player.x + game->player.delta_x * 5, game->player.y + game->player.delta_y * 5, YELLOW);
	//draw_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.mlx_img, 0, 0);
	return (0);
}
int	main()
{
	t_game	game;
	
	ft_init(&game);
	ft_get_map(&game, "map.txt");
	ft_convert_to_int_map(&game);
	printf("Converted Integer Array:\n");
    for (int i = 0; i < game.height; i++) {
        for (int j = 0; j < game.width; j++) {
            printf("%d ", game.int_map[i][j]);
        }
        printf("\n");
    }
	printf("MAP WIDTH %d\nMAP HEIGHT %d\n", game.width, game.height);
	game.img.mlx_img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	game.img.addr = mlx_get_data_addr(game.img.mlx_img, &game.img.bpp,
			&game.img.line_len, &game.img.endian);
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_hook(game.win, 17, 1L << 17, ft_close_x, &game);
	mlx_loop(game.mlx);
	return (0);
}
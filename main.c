/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:49:32 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/05 14:40:45 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_close_x(void)
{
	exit(0);
}

void	ft_draw_line(t_game *game, int begin_x, int begin_y, int end_x,
		int end_y, int color)
{
	float	delta_x;
	float	delta_y;
	int		pixels;
	float	pixel_x;
	float	pixel_y;

	delta_x = end_x - begin_x;
	delta_y = end_y - begin_y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = begin_x;
	pixel_y = begin_y;
	while (pixels)
	{
		img_pix_put(game, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}



int	render(t_game *game)
{
	ft_calculate_speed(game);
	ft_move(game);
	ft_draw_background(game);
	ft_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.mlx_img, 0, 0);
	ft_draw_2d_map(game);
	img_pix_put(game, game->player.x * SQUARE_SIZE, game->player.y * SQUARE_SIZE, BLACK);
	ft_draw_line(game, game->player.x, game->player.y, game->rays.delta_dist_x, game->rays.delta_dist_y, BLACK);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		printf("Not enough arguments!\n");
		return (1);
	}
	if (ft_checkfile(av[1]) == 1)
	{
		ft_printf("Error\nWrong file format!\n");
		return (1);
	}
	ft_init(&game);
	game.file_name = ft_strdup(av[1]);
	ft_handle_input(&game);
	ft_convert_map(&game);
	ft_find_player_position(&game);
	ft_player_angle(&game);
	ft_mlx_init(&game);
	ft_all_textures(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game);
	mlx_hook(game.win, 17, 1L << 17, ft_close_x, &game);
	mlx_loop(game.mlx);
	mlx_do_sync(game.mlx);
	return (0);
}

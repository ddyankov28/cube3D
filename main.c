/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:49:32 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/09 17:14:19 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_close_x(t_game *game)
{
	mlx_destroy_image(game->mlx, game->north.mlx_img);
	mlx_destroy_image(game->mlx, game->east.mlx_img);
	mlx_destroy_image(game->mlx, game->west.mlx_img);
	mlx_destroy_image(game->mlx, game->south.mlx_img);
	ft_free_game(game, NULL, 0);
	return (0);
}

int	render(t_game *game)
{
	ft_move(game);
	ft_draw_background(game);
	ft_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.mlx_img, 0, 0);
	ft_draw_2d_map(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (printf("Not enough arguments!\n"), 1);
	if (ft_checkfile(av[1]))
		return (printf("Error\nWrong file format!\n"), 1);
	ft_init(&game);
	game.file_name = ft_strdup(av[1]);
	if (!game.file_name)
		return (1);
	ft_handle_input(&game);
	ft_find_player_position(&game);
	ft_player_angle(&game);
	ft_mlx_init(&game);
	ft_all_textures(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game);
	mlx_hook(game.win, 17, 1L << 17, ft_close_x, &game);
	mlx_loop(game.mlx);
	return (0);
}

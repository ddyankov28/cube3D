/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:49:32 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/27 12:38:12 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_close_x(void)
{
	exit(0);
}

int	render(t_game *game)
{
	ft_draw_background(game);
	ft_draw_2d_map(game);
	ft_draw_circle(game);
	rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.mlx_img, 0, 0);
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
	ft_events_init(&game);
	game.file_name = ft_strdup(av[1]);
	ft_rays_init(&game);
	//ft_get_map(&game, "map.txt");
	ft_handle_input(&game);
	ft_convert_map(&game);
	ft_find_player_position(&game);
	ft_player_angle(&game);
	ft_mlx_init(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game);
	mlx_hook(game.win, 17, 1L << 17, ft_close_x, &game);
	mlx_loop(game.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:49:32 by ddyankov          #+#    #+#             */
/*   Updated: 2023/08/22 18:27:33 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_2d_map(t_game *game);
void	ft_draw_player(t_game *game);

void	ft_get_map(t_game *game, char *map_name)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error\nFile does not exist", 2);
		exit(1);
	}
	while (1)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
			break ;
		i++;
		game->height++;
	}
	game->width = ft_strlen(game->map[0]) - 1;
	close (fd);
}

int	ft_key_press(int key, t_game *game)
{
	printf("%d\n", key);
	if (key == ESCAPE)
		exit(0);
	if (key == W)
		game->player_y -= 10;
	if (key == S)
		game->player_y += 10;
	if (key == A)
		game->player_x -= 10;
	if (key == D)
		game->player_x += 10;
	mlx_clear_window(game->mlx, game->win);
	ft_draw_2d_map(game);
	ft_draw_player(game);
	return (0);
}
void	ft_draw_square(t_game *game, int color)
{
	int x = 0;
	int y = 0;
	
	while (x < game->square_size)
	{
		y = 0;
		while (y < game->square_size)
		{
			mlx_pixel_put(game->mlx, game->win, game->square_x + x, game->square_y + y, color);
			y++;
		}
		x++;
	}
}

void	ft_draw_wall_or_empty(t_game *game, int y , int x)
{
	if (game->map[y][x] == 1)
		ft_draw_square(game, 0x6484EE);
	else
		ft_draw_square(game, 0xFFFFFF);
	
}

void	ft_draw_2d_map(t_game *game)
{
	int x, y = 0;
	while (y < game->height)
	{
		game->square_x = 10;
		x = 0;
		while (x < game->width)
		{
			ft_draw_wall_or_empty(game,y, x);
			game->square_x += game->square_size + 5;
			x++;
		}
		y++;
		game->square_y += game->square_size + 5;
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
			mlx_pixel_put(game->mlx, game->win, game->player_x + x, game->player_y + y, 0xFF0000);
			y++;
		}
		x++;
	}
}

int	ft_close_x()
{
	exit(0);
}

int	main()
{
	t_game	game;
	game.square_x = 10;
	game.square_y = 10;
	game.square_size = 64;
	game.map = malloc(10000);
	ft_get_map(&game, "map.txt");
	int i = 0;
	int j = 0;
	while (i < game.width)
	{
		j = 0;
		while(j < game.height)
		{
			printf("%c ", game.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	game.player_x = 400;
	game.player_y = 300;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "cube3D");
	ft_draw_2d_map(&game);
	ft_draw_player(&game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_hook(game.win, 17, 1L << 17, ft_close_x, &game);
	mlx_loop(game.mlx);
	return (0);
}
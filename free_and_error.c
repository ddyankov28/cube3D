/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:01:24 by vstockma          #+#    #+#             */
/*   Updated: 2023/10/09 17:36:46 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_if_close_error(t_game *game)
{
	free(game->content_str);
	free(game->file_name);
	exit(1);
}

void	ft_free_malloc(t_game *game, int i, int fd)
{
	printf("Error\nMalloc allocation failed\n");
	if (i == 1)
	{
		if (fd != -1)
			close(fd);
		free(game->file_name);
	}
	else if (i == 2 || i == 3 || i == 5)
		ft_free_content(game);
	else if (i == 4)
	{
		free(game->tmp_string);
		ft_free_content(game);
	}
	else if (i == 6)
	{
		ft_free_2d_arr(game->map);
		ft_free_content(game);
	}
	exit(1);
}

static void	ft_free_mlx_pointer(t_game *game)
{
	if (game->mlx)
	{
		if (game->img.mlx_img)
			mlx_destroy_image(game->mlx, game->img.mlx_img);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

void	ft_free_game(t_game *game, char *s, int i)
{
	ft_free_mlx_pointer(game);
	ft_free_2d_arr(game->map);
	ft_free_textures_and_colors(game);
	if (i)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(s, 2);
	}
	exit (i);
}

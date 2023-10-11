/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:18:21 by vstockma          #+#    #+#             */
/*   Updated: 2023/10/11 10:15:20 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_free_textures_and_colors(t_game *game)
{
	if (game->ceiling_color != NULL)
		free(game->ceiling_color);
	if (game->floor_color != NULL)
		free(game->floor_color);
	if (game->no_texture != NULL)
		free(game->no_texture);
	if (game->so_texture != NULL)
		free(game->so_texture);
	if (game->we_texture != NULL)
		free(game->we_texture);
	if (game->ea_texture != NULL)
		free(game->ea_texture);
}

void	ft_free_colors_textures_error(t_game *game, char *tmp, int i)
{
	if (i == 1)
	{
		ft_printf("Error\nOne of the textures is not in the right format!\n");
		free(tmp);
	}
	else if (i == 2)
	{
		ft_printf("Error\nOne of the colors is not in the right format!\n");
		free(game->tmp_string);
	}
	else if (i == 3)
	{
		free(game->tmp_string);
		ft_printf("Error\n");
		ft_printf("The numbers of the color have to be between 0 and 255\n");
	}
	ft_free_content(game);
	exit(1);
}

void	ft_free_map_error(t_game *game, int i)
{
	if (i == 0)
		printf("Error\nft_strdup failed\n");
	if (i == 1)
		printf("Error\nCheck your player!\n");
	else if (i == 2)
		printf("Error\nSomething wrong with the map!\n");
	else if (i == 3)
		printf("Error\nWrong characters in map!\n");
	else if (i == 4)
		printf("Error\nPlayer is not surrounded by walls!\n");
	else if (i == 5)
		printf("Error\nInavlid map!\n");
	else if (i == 6)
	{
		ft_printf("Error opening file!\n");
		exit(1);
	}
	else if (i == 7)
	{
		printf("Error\nSomething is wrong in the input file!\n");
		exit(1);
	}
	ft_free_2d_arr(game->map);
	ft_free_content(game);
	exit(1);
}

void	ft_free_content(t_game *game)
{
	ft_free_2d_arr(game->content);
	ft_free_textures_and_colors(game);
	free(game->file_name);
	exit(1);
}

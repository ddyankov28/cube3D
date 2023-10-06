/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_receiving.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:41:14 by vstockma          #+#    #+#             */
/*   Updated: 2023/10/06 15:43:05 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_if_conditions(t_game *game, int i)
{
	if (game->all_done == 6)
		return (1);
	if (ft_strncmp_textures(game, game->content[i], "NO", 2) == 0)
		game->no_texture = ft_strdup(game->content[i]);
	else if (ft_strncmp_textures(game, game->content[i], "SO", 2) == 0)
		game->so_texture = ft_strdup(game->content[i]);
	else if (ft_strncmp_textures(game, game->content[i], "EA", 2) == 0)
		game->ea_texture = ft_strdup(game->content[i]);
	else if (ft_strncmp_textures(game, game->content[i], "WE", 2) == 0)
		game->we_texture = ft_strdup(game->content[i]);
	else if (ft_strncmp_colors(game, game->content[i], "F", 1) == 0)
		game->floor_color = ft_strdup(game->content[i]);
	else if (ft_strncmp_colors(game, game->content[i], "C", 1) == 0)
		game->ceiling_color = ft_strdup(game->content[i]);
	else if (game->content[i][0] != '\n')
	{
		ft_free_content(game);
		ft_free_map_error(game, 7);
	}
	return (0);
}

static int	ft_check_extractions(t_game *game, int i)
{
	if (game->all_done == 6)
	{
		ft_check_textures(game);
		ft_check_colors(game);
		if (ft_get_map(game, i) == 1)
			ft_free_map_error(game, 2);
	}
	return (0);
}

static int	ft_extract_content(t_game *game)
{
	int	i;

	i = 0;
	while (game->content[i])
	{
		if (ft_if_conditions(game, i) == 1)
			break ;
		i++;
		if (game->all_done == 6)
			break ;
	}
	ft_check_extractions(game, i);
	return (0);
}

static int	ft_insert_content(t_game *game)
{
	int	i;

	i = 0;
	game->content = ft_split(game->content_str, '\n');
	if (!game->content)
	{
		free(game->content_str);
		ft_free_malloc(game, 5, 0);
	}
	while (game->content[i])
	{
		i++;
		game->lines++;
	}
	return (0);
}

int	ft_get_file_content(t_game *game)
{
	int	fd;

	fd = open(game->file_name, O_RDONLY);
	if (fd < 0)
		ft_free_map_error(game, 6);
	game->content_str = ft_read_file(fd);
	if (!game->content_str)
		ft_free_malloc(game, 1, fd);
	close(fd);
	ft_insert_content(game);
	free(game->content_str);
	if (game->content[0] == NULL)
	{
		ft_free_2d_arr(game->content);
		free(game->file_name);
		exit(1);
	}
	ft_extract_content(game);
	return (0);
}

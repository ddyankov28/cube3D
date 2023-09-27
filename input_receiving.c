/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_receiving.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:41:14 by vstockma          #+#    #+#             */
/*   Updated: 2023/09/27 11:19:12 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_if_conditions(t_game *game, int i)
{
	if (game->all_done == 6)
		return (1);
	if (ft_strncmp_textures(game, game->content[i], "NO", 2) == 0)
		game->img.no_texture = ft_strdup(game->content[i]);
	else if (ft_strncmp_textures(game, game->content[i], "SO", 2) == 0)
		game->img.so_texture = ft_strdup(game->content[i]);
	else if (ft_strncmp_textures(game, game->content[i], "EA", 2) == 0)
		game->img.ea_texture = ft_strdup(game->content[i]);
	else if (ft_strncmp_textures(game, game->content[i], "WE", 2) == 0)
		game->img.we_texture = ft_strdup(game->content[i]);
	else if (ft_strncmp_colors(game, game->content[i], "F", 1) == 0)
		game->img.floor_color = ft_strdup(game->content[i]);
	else if (ft_strncmp_colors(game, game->content[i], "C", 1) == 0)
		game->img.ceiling_color = ft_strdup(game->content[i]);
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

static int	ft_insert_content(t_game *game, int fd)
{
	int	i;

	i = 0;
	while (1)
	{
		game->content[i] = get_next_line(fd);
		if (game->content[i] == NULL)
			break ;
		game->lines++;
		i++;
	}
	game->content[i] = NULL;
	return (0);
}

int	ft_get_file_content(t_game *game)
{
	int	fd;
	int	count;

	fd = open(game->file_name, O_RDONLY);
	if (fd < 0)
	{
		free(game->file_name);
		ft_free_map_error(game, 6);
	}
	count = ft_linecount(fd);
	fd = open(game->file_name, O_RDONLY);
	game->content = malloc(sizeof(char *) * (count + 1));
	ft_insert_content(game, fd);
	close(fd);
	ft_extract_content(game);
	return (0);
}

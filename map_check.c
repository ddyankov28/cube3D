/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:00:43 by valentin          #+#    #+#             */
/*   Updated: 2023/09/27 11:23:48 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_count_players(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'N' || game->map[i][j] == 'E'
		|| game->map[i][j] == 'S' || game->map[i][j] == 'W')
	{
		game->player.x = j;
		game->player.y = i;
		return (1);
	}
	return (0);
}

int	ft_get_player_position(t_game *game)
{
	int	count_players;
	int	i;
	int	j;

	count_players = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			count_players += ft_count_players(game, i, j);
			j++;
		}
		i++;
	}
	if (count_players != 1)
		ft_free_map_error(game, 1);
	else if (i <= 1)
		ft_free_map_error(game, 5);
	return (0);
}

int	ft_check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'N' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'S' && game->map[i][j] != 'W'
				&& game->map[i][j] != ' ')
				ft_free_map_error(game, 3);
			j++;
		}
		game->rows++;
		i++;
	}
	ft_change_map(game);
	ft_check_walls(game);
	return (0);
}

int	ft_checkfile(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i++] == '.')
		{
			if (str[i++] != 'c')
				return (1);
			if (str[i++] != 'u')
				return (1);
			if (str[i++] != 'b')
				return (1);
			if (str[i] != '\0')
				return (1);
			count++;
		}
	}
	if (count == 0)
		return (1);
	return (0);
}

int	ft_get_map(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->content[i] && game->content[i][0] == '\n')
		i++;
	game->map = malloc(sizeof(char *) * game->lines);
	while (game->content[i])
	{
		if (game->content[i][0] == '\n')
			break ;
		game->map[j] = ft_strdup(game->content[i]);
		j++;
		i++;
	}
	if (game->content[i] != NULL)
	{
		while (game->content[i])
		{
			if (game->content[i][0] != '\n')
				return (1);
			i++;
		}
	}
	game->map[j] = NULL;
	return (0);
}

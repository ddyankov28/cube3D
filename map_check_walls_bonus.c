/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_walls_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:52:45 by vstockma          #+#    #+#             */
/*   Updated: 2023/10/10 14:33:47 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

static int	ft_check_top_row(t_game *game, int i, int j)
{
	if (i == 0 && j == 0)
	{
		if ((game->map[i][j + 1] != 'x' && game->map[i][j + 1] != '1')
			|| (game->map[i + 1][j] != 'x' && game->map[i + 1][j] != '1'))
			return (1);
	}
	else if (i == 0)
	{
		if ((game->map[i][j + 1] != 'x' && game->map[i][j + 1] != '1'
				&& game->map[i][j + 1] != '\0') || (game->map[i][j - 1] != 'x'
				&& game->map[i][j - 1] != '1'))
			return (1);
		if (j < ft_strlen(game->map[i + 1]))
		{
			if (game->map[i + 1][j] != 'x' && game->map[i + 1][j] != '1')
				return (1);
		}
	}
	return (0);
}

static int	ft_check_last_row(t_game *game, int i, int j)
{
	if (i == game->height - 1 && j == 0)
	{
		if ((game->map[i][j + 1] != 'x' && game->map[i][j + 1] != '1'
				&& game->map[i][j + 1] != '\0'))
			return (1);
		if (j < ft_strlen(game->map[i - 1]))
		{
			if (game->map[i - 1][j] != 'x' && game->map[i - 1][j] != '1')
				return (1);
		}
	}
	else if (i == game->height - 1)
	{
		if ((game->map[i][j + 1] != 'x' && game->map[i][j + 1] != '1'
				&& game->map[i][j + 1] != '\0') || (game->map[i][j - 1] != 'x'
				&& game->map[i][j - 1] != '1'))
			return (1);
		if (j < ft_strlen(game->map[i - 1]))
		{
			if (game->map[i - 1][j] != 'x' && game->map[i - 1][j] != '1')
				return (1);
		}
	}
	return (0);
}

static int	ft_check_middle_part(t_game *game, int i, int j)
{
	if ((game->map[i][j + 1] != 'x' && game->map[i][j + 1] != '1'
			&& game->map[i][j + 1] != '\0') || (game->map[i][j - 1] != 'x'
			&& game->map[i][j - 1] != '1'))
		return (1);
	if (j < ft_strlen(game->map[i + 1]))
	{
		if (game->map[i + 1][j] != 'x' && game->map[i + 1][j] != '1')
			return (1);
	}
	if (j < ft_strlen(game->map[i - 1]))
	{
		if (game->map[i - 1][j] != 'x' && game->map[i - 1][j] != '1')
			return (1);
	}
	return (0);
}

static int	ft_check_x_surroundings(t_game *game, int i, int j)
{
	if (i == 0)
	{
		if (ft_check_top_row(game, i, j) == 1)
			return (1);
	}
	else if (i == game->height - 1)
	{
		if (ft_check_last_row(game, i, j) == 1)
			return (1);
	}
	else if (j == 0)
	{
		if ((game->map[i + 1][j] != 'x' && game->map[i + 1][j] != '1')
			|| (game->map[i - 1][j] != 'x' && game->map[i - 1][j] != '1')
			|| (game->map[i][j + 1] != 'x' && game->map[i][j + 1] != '1'
				&& game->map[i][j + 1] != '\0'))
			return (1);
	}
	else
	{
		if (ft_check_middle_part(game, i, j) == 1)
			return (1);
	}
	return (0);
}

int	ft_check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'x')
			{
				if (ft_check_x_surroundings(game, i, j) == 1)
					ft_free_map_error(game, 4);
			}
			j++;
		}
		i++;
	}
	return (0);
}

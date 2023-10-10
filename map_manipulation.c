/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:53:08 by vstockma          #+#    #+#             */
/*   Updated: 2023/10/10 12:11:32 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_insert_x_right(t_game *game, int i, int j)
{
	j -= 1;
	while (game->map[i][j] && game->map[i][j] != '1' && j >= 0)
	{
		game->map[i][j] = 'x';
		if (j == 0)
			break ;
		j--;
	}
	return (0);
}

static int	ft_insert_x_left(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '1'
			&& game->map[i][j] != '\n')
		{
			game->map[i][j] = 'x';
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_insert_x(t_game *game, int i)
{
	int	j;

	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (i == 0)
			{
				if (game->map[i][j] != '1')
					game->map[i][j] = 'x';
			}
			if (i == game->height - 1)
			{
				if (game->map[i][j] != '1')
					game->map[i][j] = 'x';
			}
			if (game->map[i][j] == ' ')
				game->map[i][j] = 'x';
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_change_map(t_game *game)
{
	int	i;

	i = 0;
	ft_change_len(game);
	ft_insert_x_left(game);
	while (game->map[i])
	{
		ft_insert_x_right(game, i, ft_strlen(game->map[i]));
		i++;
	}
	i = 0;
	ft_insert_x(game, i);
	return (0);
}

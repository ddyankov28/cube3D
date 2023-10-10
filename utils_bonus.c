/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:10:50 by vstockma          #+#    #+#             */
/*   Updated: 2023/10/10 14:33:47 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

static void	ft_if_smaller_than_width(t_game *game, char *tmp, int i, int j)
{
	while (j < game->width)
		tmp[j++] = 'x';
	tmp[j] = '\0';
	free(game->map[i]);
	game->map[i] = ft_strdup(tmp);
	if (!game->map[i])
	{
		free(tmp);
		ft_free_malloc(game, 6, 0);
	}
}

int	ft_change_len(t_game *game)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		tmp = malloc(game->width + 2);
		if (!tmp)
			ft_free_malloc(game, 6, 0);
		while (game->map[i][j])
		{
			tmp[j] = game->map[i][j];
			j++;
		}
		if (j < game->width)
			ft_if_smaller_than_width(game, tmp, i, j);
		free(tmp);
		i++;
	}
	return (0);
}

int	ft_get_width(t_game *game)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	j = 0;
	width = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (width < j)
			width = j;
		i++;
	}
	return (width);
}

int	ft_check_line(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->content[i][j])
	{
		if (game->content[i][j] != ' ' && game->content[i][j] != '\n')
			return (1);
		j++;
	}
	return (0);
}

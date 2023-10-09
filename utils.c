/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:10:50 by vstockma          #+#    #+#             */
/*   Updated: 2023/10/09 16:56:54 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_if_smaller_than_width(t_game *game, char *tmp, int i, int j)
{
	while (j < game->width)
		tmp[j++] = 'x';
	tmp[j] = '\0';
	printf("%d\n", ft_strlen(tmp));
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

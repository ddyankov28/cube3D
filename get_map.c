/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:03:33 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/05 10:58:01 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


void	ft_convert_map(t_game *game)
{
	int	i;
	int	j;

	game->imap = (int **)malloc(game->height * sizeof(int *));
	i = -1;
	while (++i < game->height)
	{
		game->imap[i] = (int * )malloc(game->width * sizeof(int));
		j = -1;
		while (++j < game->width)
		{
			game->imap[i][j] = game->map[i][j] - '0';
			if (game->imap[i][j] != 1 && game->imap[i][j] != 0)
				game->imap[i][j] = 0; 
		}
	}
}

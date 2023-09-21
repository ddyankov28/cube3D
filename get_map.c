/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:03:33 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/20 14:48:56 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_get_map(t_game *game, char *map_name)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error\nFile does not exist", 2);
		exit(1);
	}
	while (1)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i] == NULL)
			break ;
		i++;
		game->height++;
	}
	game->width = ft_strlen(game->map[0]) - 1;
	close (fd);
}


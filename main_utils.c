/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:17:18 by valentin          #+#    #+#             */
/*   Updated: 2023/10/06 12:02:34 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_handle_input(t_game *game)
{
	ft_get_file_content(game);
	ft_free_2d_arr(game->content);
	free(game->file_name);
	ft_check_map(game);
	ft_get_player_position(game);
	return (0);
}

int	ft_linecount(int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		count++;
	}
	free(line);
	line = NULL;
	close(fd);
	return (count);
}

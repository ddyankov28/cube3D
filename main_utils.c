/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:17:18 by valentin          #+#    #+#             */
/*   Updated: 2023/10/06 14:35:54 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_read_file(int fd)
{
	char	*content;
	char	*add;
	char	*tmp;
	int		i;

	content = ft_calloc(1, 1);
	if (!content)
		return (0);
	add = ft_calloc(1, 101);
	if (!add)
		return (free(content), NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, add, 100);
		if (i < 0)
			return(free(content), free(add), NULL);
		add[i] = '\0';
		tmp = content;
		content = ft_strjoin(content, add);
		if (!content)
			return (free(tmp), free(add), NULL);
		free(tmp);
	}
	return (free(add), content);
}

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
		if (line)
			free(line);
		count++;
	}
	if (line)
		free(line);
	line = NULL;
	close(fd);
	return (count);
}

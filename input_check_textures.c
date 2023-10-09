/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:59:14 by vstockma          #+#    #+#             */
/*   Updated: 2023/10/09 13:01:53 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_strncmp_textures(t_game *game, char *s1, const char *s2, size_t n)
{
	unsigned char	*b;
	unsigned char	*c;
	size_t			a;
	size_t			x;

	b = (unsigned char *)s1;
	c = (unsigned char *)s2;
	x = 0;
	while (b[x] == ' ')
		x++;
	a = 0;
	while (b[x] == c[a] && b[x] != '\0' && c[a] != '\0' && a < n)
	{
		a++;
		x++;
	}
	if (b[x] != ' ' && b[x] != '.')
		return (1);
	if (a == n)
	{
		game->all_done++;
		return (0);
	}
	return (b[x] - c[a]);
}

static char	*ft_put_tmp(char *tmp, int i, char *str)
{
	int	x;

	x = 0;
	while (str[i])
	{
		tmp[x++] = str[i++];
		if (str[i] == ' ')
		{
			while (str[i] && str[i] == ' ')
				i++;
			if (str[i] != '\0' && str[i] != '\n')
				return (NULL);
		}
		if (str[i] == '\n')
			break ;
	}
	if (x < 3)
		return (NULL);
	tmp[x] = '\0';
	return (tmp);
}

static char	*ft_trim_string_textures(t_game *game, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(ft_strlen(str));
	if (!tmp)
		ft_free_malloc(game, 3, 0);
	while (str[i] == ' ')
		i++;
	i += 2;
	while (str[i] != '.')
	{
		if (str[i] != ' ')
			ft_free_colors_textures_error(game, tmp, 1);
		i++;
	}
	if (str[i + 1] != '/')
		ft_free_colors_textures_error(game, tmp, 1);
	if (ft_put_tmp(tmp, i, str) == NULL)
		ft_free_colors_textures_error(game, tmp, 1);
	free(str);
	return (tmp);
}

int	ft_check_textures(t_game *game)
{
	if (!game->no_texture || !game->so_texture || !game->we_texture
		|| !game->ea_texture)
		ft_free_content(game);
	game->no_texture = ft_trim_string_textures(game, game->no_texture);
	game->so_texture = ft_trim_string_textures(game, game->so_texture);
	game->we_texture = ft_trim_string_textures(game, game->we_texture);
	game->ea_texture = ft_trim_string_textures(game, game->ea_texture);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:57:32 by vstockma          #+#    #+#             */
/*   Updated: 2023/09/27 11:07:27 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_strncmp_colors(t_game *game, char *s1, const char *s2, size_t n)
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
	if (b[x] != ' ')
		return (1);
	if (a == n)
	{
		game->all_done++;
		return (0);
	}
	return (b[x] - c[a]);
}

static int	ft_extansion_colors(t_game *game, int i, char *str)
{
	int		j;
	char	*number;

	while (str[i] == ' ')
		i++;
	j = 0;
	number = malloc(ft_strlen(str));
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		number[j++] = str[i];
		game->tmp_string[game->index++] = str[i];
		i++;
		if (str[i] == '\n')
			break ;
	}
	number[j++] = '\0';
	if (ft_atoi(number) > 255)
	{
		free(number);
		ft_free_colors_textures_error(game, NULL, 3);
	}
	free(number);
	while (str[i] == ' ')
		i++;
	return (i);
}

static int	ft_get_color(int i, char *str, t_game *game)
{
	game->index = 0;
	i = ft_extansion_colors(game, i, str);
	if (i == 0)
		return (1);
	if (str[i++] != ',')
		return (1);
	game->tmp_string[game->index++] = ',';
	i = ft_extansion_colors(game, i, str);
	if (i == 0)
		return (1);
	if (str[i++] != ',')
		return (1);
	game->tmp_string[game->index++] = ',';
	i = ft_extansion_colors(game, i, str);
	if (i == 0)
		return (1);
	if (str[i] != '\n')
		return (1);
	game->tmp_string[game->index++] = '\0';
	return (0);
}

static int	ft_trim_string_colors(char *str, t_game *game)
{
	int	i;

	i = 0;
	game->tmp_string = malloc(ft_strlen(str));
	while (str[i] == ' ')
		i++;
	i += 1;
	while (ft_isdigit(str[i]) == 0)
	{
		if (str[i] != ' ')
			ft_free_colors_textures_error(game, NULL, 2);
		i++;
	}
	if (ft_get_color(i, str, game) == 1)
		ft_free_colors_textures_error(game, NULL, 2);
	return (0);
}

int	ft_check_colors(t_game *game)
{
	ft_trim_string_colors(game->img.floor_color, game);
	free(game->img.floor_color);
	game->img.floor_color = ft_strdup(game->tmp_string);
	free(game->tmp_string);
	ft_trim_string_colors(game->img.ceiling_color, game);
	free(game->img.ceiling_color);
	game->img.ceiling_color = ft_strdup(game->tmp_string);
	free(game->tmp_string);
	return (0);
}

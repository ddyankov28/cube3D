/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:57:32 by vstockma          #+#    #+#             */
/*   Updated: 2023/10/10 11:38:04 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_check_num(t_game *game, char *number)
{
	if (ft_atoi(number) > 255 || !ft_strcmp(number, "\0"))
	{
		free(number);
		ft_free_colors_textures_error(game, NULL, 3);
	}
}

static int	ft_extansion_colors(t_game *game, int i, char *str)
{
	int		j;
	char	*number;

	while (str[i] == ' ')
		i++;
	j = 0;
	number = malloc(ft_strlen(str));
	if (!number)
		ft_free_malloc(game, 4, 0);
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		number[j++] = str[i];
		game->tmp_string[game->index++] = str[i];
		i++;
		if (str[i] == '\n')
			break ;
	}
	number[j++] = '\0';
	ft_check_num(game, number);
	free(number);
	while (str[i] == ' ')
		i++;
	return (i);
}

int	ft_get_color(int i, char *str, t_game *game)
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
	if (str[i] != '\n' && str[i] != '\0')
		return (1);
	game->tmp_string[game->index++] = '\0';
	return (0);
}

static int	ft_rgb_to_int(char *color)
{
	int	i;
	int	j;
	int	rgb[3];

	i = 0;
	j = 0;
	while (i < 3)
		rgb[i++] = 0;
	i = 0;
	while (color && color[i] && j < 3)
	{
		while (ft_isdigit(color[i]))
		{
			rgb[j] = rgb[j] * 10;
			rgb[j] = rgb[j] + (color[i] - '0');
			i++;
		}
		if (color[i] == '\0')
			break ;
		i++;
		j++;
	}
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	ft_check_colors(t_game *game)
{
	if (!game->ceiling_color || !game->floor_color)
		ft_free_content(game);
	ft_trim_string_colors(game->floor_color, game);
	free(game->floor_color);
	game->floor_color = ft_strdup(game->tmp_string);
	if (!game->floor_color)
	{
		printf("Error\nft_strdup failed\n");
		free(game->tmp_string);
		ft_free_content(game);
	}
	free(game->tmp_string);
	ft_trim_string_colors(game->ceiling_color, game);
	free(game->ceiling_color);
	game->ceiling_color = ft_strdup(game->tmp_string);
	if (!game->ceiling_color)
	{
		printf("Error\nft_strdup failed\n");
		free(game->tmp_string);
		ft_free_content(game);
	}
	free(game->tmp_string);
	game->floor = ft_rgb_to_int(game->floor_color);
	game->ceiling = ft_rgb_to_int(game->ceiling_color);
	return (0);
}

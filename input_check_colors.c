/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:57:32 by vstockma          #+#    #+#             */
/*   Updated: 2023/10/06 12:50:07 by vstockma         ###   ########.fr       */
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
	if (!game->tmp_string)
		ft_free_malloc(game, 5, 0);
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

void	ft_init_arr(int *rgb, int size)
{
	int	i;

	i = 0;
	while (i < size)
		rgb[i++] = 0;
}
static int	ft_rgb_to_int(char *color)
{
	int	i;
	int	j;
	int	rgb[3];

	i = 0;
	j = 0;
	ft_init_arr(rgb, 3);
	while (color[i] && j < 3)
	{
		while (ft_isdigit(color[i]))
		{
			rgb[j] = rgb[j] * 10;
			rgb[j] = rgb[j] + (color[i] - '0');
			i++;
		}
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

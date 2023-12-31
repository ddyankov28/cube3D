/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_colors_utils_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:22:26 by vstockma          #+#    #+#             */
/*   Updated: 2023/10/10 14:33:47 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

static void	ft_check_for_double_col(t_game *game, const char *col)
{
	static int	f;
	static int	c;

	if (!ft_strcmp(col, "F"))
		f++;
	else if (!ft_strcmp(col, "C"))
		c++;
	if (f > 1 || c > 1)
	{
		printf("Error\nColors repeated!\n");
		ft_free_content(game);
	}
}

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
		ft_check_for_double_col(game, s2);
		return (0);
	}
	return (b[x] - c[a]);
}

int	ft_trim_string_colors(char *str, t_game *game)
{
	int	i;

	i = 0;
	game->tmp_string = malloc(ft_strlen(str));
	if (!game->tmp_string)
		ft_free_malloc(game, 5, 0);
	while (str[i] == ' ')
		i++;
	i += 1;
	while (str[i] && ft_isdigit(str[i]) == 0)
	{
		if (str[i] != ' ')
			ft_free_colors_textures_error(game, NULL, 2);
		i++;
	}
	if (ft_get_color(i, str, game) == 1)
		ft_free_colors_textures_error(game, NULL, 2);
	return (0);
}

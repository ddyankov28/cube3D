/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:15:10 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/09 17:14:46 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_free_img_ptr(t_game *game)
{
	if (game->north.mlx_img)
		mlx_destroy_image(game->mlx, game->north.mlx_img);
	if (game->south.mlx_img)
		mlx_destroy_image(game->mlx, game->south.mlx_img);
	if (game->west.mlx_img)
		mlx_destroy_image(game->mlx, game->west.mlx_img);
	if (game->east.mlx_img)
		mlx_destroy_image(game->mlx, game->east.mlx_img);
}

static void	ft_load_texture(t_game *game, t_img *tex, char *texture_path)
{
	tex->mlx_img = mlx_xpm_file_to_image(game->mlx, texture_path,
			&tex->size, &tex->size);
	if (tex->mlx_img == NULL)
	{
		ft_free_img_ptr(game);
		ft_free_game(game, "Getting texture", 1);
		exit(1);
	}
	tex->addr = mlx_get_data_addr(tex->mlx_img, &tex->bpp, &tex->line_len,
			&tex->endian);
	if (tex->addr == NULL)
	{
		ft_free_img_ptr(game);
		ft_free_game(game, "Getting adress", 1);
		exit(1);
	}
}

void	ft_all_textures(t_game *game)
{
	ft_load_texture(game, &game->north, game->no_texture);
	ft_load_texture(game, &game->south, game->so_texture);
	ft_load_texture(game, &game->east, game->ea_texture);
	ft_load_texture(game, &game->west, game->we_texture);
	if (game->north.size != game->south.size
		|| game->north.size != game->east.size
		|| game->north.size != game->west.size)
	{
		ft_free_img_ptr(game);
		ft_free_game(game, "Img Size does not much", 1);
		exit(1);
	}
}

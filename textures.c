/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:15:10 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/05 12:26:21 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void    ft_load_texture(t_game *game, t_img *tex, char *texture_path)
{
    tex->mlx_img = mlx_xpm_file_to_image(game->mlx, texture_path, &game->img.size, &game->img.size);
    if (tex->mlx_img == NULL)
    {
        printf("Error\nGetting texture\n");
        exit(1);
    }
    tex->addr = mlx_get_data_addr(tex->mlx_img, &tex->bpp, &tex->line_len, &tex->endian);
    if (tex->addr == NULL)
    {
        printf("Error\nGetting adress\n");
        exit(1);
    }
}

void    ft_all_textures(t_game *game)
{
    ft_load_texture(game, &game->north, game->no_texture);
    ft_load_texture(game, &game->south, game->so_texture);
    ft_load_texture(game, &game->east, game->ea_texture);
    ft_load_texture(game, &game->west, game->we_texture);
}



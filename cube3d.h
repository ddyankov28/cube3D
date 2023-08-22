/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:50:02 by ddyankov          #+#    #+#             */
/*   Updated: 2023/08/22 17:49:06 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>

# define WIDTH 800
# define HEIGHT 600
# define ESCAPE 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define PLAYER_SIZE 10

typedef struct s_game
{
    void    *mlx;
    void    *win;
    int     player_x;
    int     player_y;
    int     width;
    int     height;
    char    **map;
    int     square_x;
    int     square_y;
    int     square_size;
}   t_game;

#endif
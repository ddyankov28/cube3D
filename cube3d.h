/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:50:02 by ddyankov          #+#    #+#             */
/*   Updated: 2023/08/25 12:48:00 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>

//Math
# define PI 3.1415926535

// Window demensions
# define WIDTH 900
# define HEIGHT 700

// Key integers
# define ESCAPE 65307
# define W 119
# define S 115
# define A 97
# define D 100

//Colors
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define BLACK 0x000000
# define RED 0xFF0000
# define YELLOW 0xFFEF00
# define GREY 0xA0A0A0

// 2Dmap player square attributes
# define PLAYER_SIZE 10

// 2Dmap wall or empty attributes
# define SQUARE_SIZE 40

# define SPEED 10

typedef struct s_img
{
    void    *mlx_img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}       t_img;

typedef struct s_player
{
    float   x;
    float   y;
    float   delta_x;
    float   delta_y;
    float   angle;
}       t_player;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    int     width;
    int     height;
    char    **map;
    int     **int_map;
    int     square_x;
    int     square_y;
    int     square_size;
    t_player player;
    t_img   img;
}       t_game;

//init
void    ft_init(t_game *game);

//map
void	ft_get_map(t_game *game, char *map_name);
void	ft_convert_to_int_map(t_game *game);

//render
void    ft_draw_background(t_game *game);
void	ft_draw_2d_map(t_game *game);
void	ft_draw_square(t_game *game, int color);
void	ft_draw_player(t_game *game);
int     img_pix_put(t_img *img, int x, int y, int color);
void	ft_draw_line(t_game *game, int x1, int y1, int x2, int y2, int color);

//move
int	ft_key_press(int key, t_game *game);

#endif
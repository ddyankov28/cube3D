/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:50:02 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/25 17:28:10 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include <stdbool.h>

//Math
# define PI 3.1415926535
# define P2 PI / 2
# define P3 3*PI / 2
# define DR 0.0174533 // one degree in radians

//Colors
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define BLACK 0x000000
# define RED 0xFF0000
# define YELLOW 0xFFEF00
# define GREY 0xA0A0A0

// 2Dmap player square attributes
# define PLAYER_SIZE 5

// 2Dmap wall or empty attributes
# define SQUARE_SIZE 32

// Angle Speed
# define ANGLE_SPEED 0.1

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

typedef struct s_moves
{
    int move_forward;
    int move_back;
    int move_left;
    int move_right;
    int rotate_left;
    int rotate_right;
}   t_moves;

typedef struct s_rays
{
    int     ray;
    int     depth_of_field;
    int     map_x;
    int     map_y;
    int     map_pos;
    float   x;
    float   y;
    float   angle;
    float   x_offset;
    float   y_offset;
    float   a_tan;
    float   n_tan;
    float   horizont_x;
    float   horizont_y;
    float   vertical_x;
    float   vertical_y;
    float   distance_horizontal;
    float   distance_vertical;
}   t_rays;

typedef struct s_scene
{
    float   distance;
    float   line_height;
}   t_scene;

typedef struct s_game
{
    int     screen_width;
    int     screen_height;
    void    *mlx;
    void    *win;
    int     width;
    int     height;
    char    **map;
    int     *imap;
    int     square_x;
    int     square_y;
    int     square_size;
    t_player player;
    t_img   img;
    t_moves moves;
    t_rays  rays;
    t_scene scene;
}       t_game;

void	ft_draw_circle(t_game *game);

float	ft_dist(float ax, float ay, float bx, float by, float ang);
//init
void    ft_init(t_game *game);
void    ft_events_init(t_game *game);
void    ft_rays_init(t_game *game);

//map
void	ft_get_map(t_game *game, char *map_name);
void	ft_convert_map(t_game *game);

//render
void	ft_draw_rays(t_game *game);
void    ft_draw_background(t_game *game);
void	ft_draw_2d_map(t_game *game);
void	ft_draw_square(t_game *game, int color);
void    img_pix_put(t_game *game, int x, int y, int color);
void	ft_draw_line(t_game *game, int begin_x, int begin_y, int end_x, int end_y, int color);
void    ft_find_player_position(t_game *game);
void    ft_player_angle(t_game *game);
void    rays(t_game *game);

// key events
int	ft_key_press(int key, t_game *game);
int ft_key_release(int key, t_game *game);

// moves
void    ft_move_forward(t_game *game);
void    ft_move_back(t_game *game);
void    ft_move_left(t_game *game);
void    ft_move_right(t_game *game);
void    ft_rotate_right(t_game *game);
void    ft_rotate_left(t_game *game);

int     render(t_game *game);

bool    ft_player_in_bounds(t_game *game);
#endif
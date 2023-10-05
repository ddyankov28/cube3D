/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:50:02 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/05 14:55:32 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <time.h>

//Math
# define PI 3.1415		//	180 degrees in radians
# define P2 1.5707		//	90 	degrees in radians
# define P3 4.7122		//	270 degrees in radians
# define DR 0.0174533   // 	1 degree 	in radians

//Colors
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define BLACK	0x000000
# define RED	0xFF0000
# define YELLOW	0xFFEF00
# define GREY	0xA0A0A0
# define WEISS	0xFFFFFF

//moves
# define TARGET_FPS 1000
# define WALK_SPEED_RATIO 3
# define ROT_SPEED_RATIO 0.8
// 2Dmap player square attributes
# define PLAYER_SIZE 5

// 2Dmap wall or empty attributes
# define SQUARE_SIZE 6

// Angle Speed
# define ANGLE_SPEED 1

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			size;
}				t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	plane_x;
	float	plane_y;
	float	dir_x;
	float	dir_y;
	float	look_left;
	float	look_right;
	float	fov;
}				t_player;

typedef struct s_moves
{
	float	difference;
	float	frame_time;
	float	time_passed;
	float	walk_speed;
	float	rotation_speed;
	clock_t	start_time;
	clock_t	prev_time;
	int		move_straight;
	int		move_side;
	int		rotate;
}				t_moves;

typedef struct s_rays
{
	float	ray_dir_x;
	float	ray_dir_y;
	float	delta_dist_x;
	float	delta_dist_y;
	int		step_x;
	int		step_y;
	float	side_dist_x;
	float	side_dist_y;
	int		side;
	float	wall_dist;
}				t_rays;

typedef struct s_game
{
	int			screen_width;
	int			screen_height;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		**map;
	int			**imap;
	int			square_x;
	int			square_y;
	int			square_size;
	char		*file_name;
	char		**content;
	int			lines;
	char		*tmp_string;
	int			index;
	int			all_done;
	int			start;
	int			wall_height;
	float		wall_coordinate;
	int			texture_x;
	int			texture_y;
	float		texture_current;
	float		texture_move;
	int			ceiling;
	int			floor;
	char		*no_texture;
	char		*ea_texture;
	char		*so_texture;
	char		*we_texture;
	char		*floor_color;
	char		*ceiling_color;
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
	t_player	player;
	t_img		img;
	t_moves		moves;
	t_rays		rays;
}				t_game;

void			ft_draw_circle(t_game *game);

float			ft_dist(float ax, float ay, float bx, float by);
//init
void			ft_init(t_game *game);
void			ft_events_init(t_game *game);
void			ft_rays_init(t_game *game);
void			ft_mlx_init(t_game *game);

//map
void			ft_convert_map(t_game *game);

//render
void			ft_draw_background(t_game *game);
void			ft_draw_2d_map(t_game *game);
void			ft_draw_square(t_game *game, int color);
void			img_pix_put(t_game *game, int x, int y, int color);
void			ft_draw_line(t_game *game, int begin_x, int begin_y, int end_x,
					int end_y, int color);
void			ft_find_player_position(t_game *game);
void			ft_player_angle(t_game *game);
void			ft_rays(t_game *game);
void    		ft_draw_3d_scene(t_game *game);
void			ft_check_ray_angle(t_game *game);
void			ft_rays_distance(t_game *game);

// key events
int				ft_key_press(int key, t_game *game);
int				ft_key_release(int key, t_game *game);


int				render(t_game *game);

//main_utils.c
int				ft_handle_input(t_game *game);
int				ft_linecount(int fd);

//map_check_walls.c
int				ft_check_walls(t_game *game);

//map_check.c
int				ft_get_player_position(t_game *game);
int				ft_check_map(t_game *game);
int				ft_checkfile(char *str);
int				ft_get_map(t_game *game, int i);


//map_manipulation.c
int				ft_change_map(t_game *game);

//input_check_colors.c
int				ft_strncmp_colors(t_game *game, char *s1, const char *s2,
					size_t n);
int				ft_check_colors(t_game *game);

//input_check_textures.c
int				ft_strncmp_textures(t_game *game, char *s1, const char *s2,
					size_t n);
int				ft_check_textures(t_game *game);

//input_receiving.c
int				ft_get_file_content(t_game *game);

//free.c
void			ft_free_content(t_game *game);
void			ft_free_colors_textures_error(t_game *game, char *tmp,
					int i);
void			ft_free_map_error(t_game *game, int i);
void			ft_free_game(t_game *game);

bool			ft_player_in_bounds(t_game *game);





void	ft_calculate_speed(t_game *game);
void    ft_straight_or_back(t_game *game, int direction);
void    ft_left_or_right(t_game *game, int direction);
void    ft_rotate(t_game *game, float angle);
void	ft_move(t_game *game);
void    ft_all_textures(t_game *game);
#endif

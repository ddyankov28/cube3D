/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:50:02 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/11 09:04:51 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_BONUS_H
# define CUBE3D_BONUS_H

# include "libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

// Math
# define DEGR_180 3.1415 // 180 degrees in radians PI
# define DEGR_90 1.5707  // 90 degrees in radians PI / 2
# define DEGR_270 4.7122 // 270 degrees in radians 3 * PI / 2

// colors
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define RED 0xFF0000
# define BLACK 0x000000

// moves
# define MOVE_SPEED 0.03
# define ROTATE_SPEED 0.01

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
	float		x;
	float		y;
	float		plane_x;
	float		plane_y;
	float		dir_x;
	float		dir_y;
	float		look_left;
	float		look_right;
	float		fov;
}				t_player;

typedef struct s_moves
{
	float		difference;
	float		frame_time;
	float		time_passed;
	int			move_straight;
	int			move_side;
	int			rotate;
}				t_moves;

typedef struct s_rays
{
	float		ray_dir_x;
	float		ray_dir_y;
	float		delta_dist_x;
	float		delta_dist_y;
	int			step_x;
	int			step_y;
	float		side_dist_x;
	float		side_dist_y;
	int			side;
	float		wall_dist;
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
	int			square_x;
	int			square_y;
	int			square_size;
	char		*file_name;
	char		*content_str;
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

// main_utils.c
int				ft_handle_input(t_game *game);
char			*ft_read_file(int fd);
int				ft_check_after_map(t_game *game, int i);

// init
void			ft_init(t_game *game);
void			ft_mlx_init(t_game *game);

// textures.c
void			ft_all_textures(t_game *game);

// render
void			ft_draw_2d_map(t_game *game);
void			ft_draw_square(t_game *game, int color);
void			ft_draw_background(t_game *game);
void			img_pix_put(t_game *game, int x, int y, int color);

// player.c
void			ft_find_player_position(t_game *game);
void			ft_player_angle(t_game *game);

// key events
int				ft_key_press(int key, t_game *game);
int				ft_key_release(int key, t_game *game);

// move.c
void			ft_move(t_game *game);
void			ft_rays(t_game *game);
void			ft_rotate(t_game *game, float angle);

// rays.c
void			ft_calculate_wall(t_game *game);

// rays_utils.c
void			ft_draw_textures(t_game *game, int x);

// map_check.c
int				ft_get_map(t_game *game, int i);
int				ft_checkfile(char *str);
int				ft_check_map(t_game *game);
int				ft_get_player_position(t_game *game);

// map_check_walls.c
int				ft_check_walls(t_game *game);

// map_manipulation.c
int				ft_change_map(t_game *game);

// input_check_colors.c
int				ft_check_colors(t_game *game);
int				ft_get_color(int i, char *str, t_game *game);

// input_check_colors_utils.c
int				ft_strncmp_colors(t_game *game, char *s1, const char *s2,
					size_t n);
int				ft_trim_string_colors(char *str, t_game *game);

// input_check_textures.c
int				ft_strncmp_textures(t_game *game, char *s1, const char *s2,
					size_t n);
int				ft_check_textures(t_game *game);

// input_receiving.c
int				ft_get_file_content(t_game *game);

// utils.c
int				ft_change_len(t_game *game);
int				ft_get_width(t_game *game);
int				ft_check_line(t_game *game, int i);

// free.c
void			ft_free_textures_and_colors(t_game *game);
void			ft_free_colors_textures_error(t_game *game, char *tmp, int i);
void			ft_free_map_error(t_game *game, int i);
void			ft_free_content(t_game *game);

// free_and_error.c
void			ft_if_close_error(t_game *game);
void			ft_free_malloc(t_game *game, int i, int fd);
void			ft_free_game(t_game *game, char *s, int i);

#endif

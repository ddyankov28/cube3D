/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:28:02 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/26 09:21:53 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"

void    check_horizontal_lines(t_game *game)
{
    game->rays.distance_horizontal = 1000000;
    game->rays.horizont_x = game->player.x;
    game->rays.horizont_y = game->player.y;
    game->rays.depth_of_field = 0;
    game->rays.a_tan = -1 / tan(game->rays.angle);
    if (game->rays.angle > PI)
    {
        game->rays.y = (((int)game->player.y / SQUARE_SIZE) * SQUARE_SIZE) - 0.0001;
        game->rays.x = (game->player.y - game->rays.y) * game->rays.a_tan + game->player.x;
        game->rays.y_offset = -SQUARE_SIZE;
        game->rays.x_offset = -game->rays.y_offset * game->rays.a_tan;
    }
    if (game->rays.angle < PI)
    {
        game->rays.y = (((int)game->player.y / SQUARE_SIZE) * SQUARE_SIZE) + SQUARE_SIZE;
        game->rays.x = (game->player.y - game->rays.y) * game->rays.a_tan + game->player.x;
        game->rays.y_offset = SQUARE_SIZE;
        game->rays.x_offset = -game->rays.y_offset * game->rays.a_tan;
    }
    if (game->rays.angle == 0 || game->rays.angle == PI)
    {
        game->rays.x = game->player.x;
        game->rays.y = game->player.y;
        game->rays.depth_of_field = 8;
    }
    while (game->rays.depth_of_field < 8)
    {
        game->rays.map_x = (int)game->rays.x / SQUARE_SIZE;
        game->rays.map_y = (int)game->rays.y / SQUARE_SIZE;
        game->rays.map_pos = game->rays.map_y * game->width + game->rays.map_x; // maybe issue
        if (game->rays.map_pos > 0 && game->rays.map_pos < game->width * game->height && game->imap[game->rays.map_pos] == 1)
        {
            game->rays.horizont_x = game->rays.x;
            game->rays.horizont_y = game->rays.y;
            game->rays.distance_horizontal = ft_dist(game->player.x, game->player.y, game->rays.horizont_x, game->rays.horizont_y, game->rays.angle);
            game->rays.depth_of_field = 8; // hit wall
        }
        else
        {
            game->rays.x += game->rays.x_offset;
            game->rays.y += game->rays.y_offset;
            game->rays.depth_of_field++;
        }
    }
}

void    check_vertical_lines(t_game *game)
{
    game->rays.distance_vertical = 1000000;
    game->rays.vertical_x = game->player.x;
    game->rays.vertical_y = game->player.y;
    game->rays.depth_of_field = 0;
    game->rays.n_tan = -tan(game->rays.angle);
    if (game->rays.angle > P2 && game->rays.angle < P3)
    {
        game->rays.x = (((int)game->player.x / SQUARE_SIZE) * SQUARE_SIZE) - 0.0001;
        game->rays.y = (game->player.x - game->rays.x) * game->rays.n_tan + game->player.y;
        game->rays.x_offset = -SQUARE_SIZE;
        game->rays.y_offset = -game->rays.x_offset * game->rays.n_tan;
    }
    if (game->rays.angle < P2 || game->rays.angle > P3)
    {
        game->rays.x = (((int)game->player.x / SQUARE_SIZE) * SQUARE_SIZE) + SQUARE_SIZE;
        game->rays.y = (game->player.x - game->rays.x) * game->rays.n_tan + game->player.y;
        game->rays.x_offset = SQUARE_SIZE;
        game->rays.y_offset = -game->rays.x_offset * game->rays.n_tan;
    }
    if (game->rays.angle == 0 || game->rays.angle == PI)
    {
        game->rays.x = game->player.x;
        game->rays.y = game->player.y;
        game->rays.depth_of_field = 8;
    }
    while (game->rays.depth_of_field < 8)
    {
        game->rays.map_x = (int)game->rays.x / SQUARE_SIZE;
        game->rays.map_y = (int)game->rays.y / SQUARE_SIZE;
        game->rays.map_pos = game->rays.map_y * game->width + game->rays.map_x; // maybe issue
        if (game->rays.map_pos > 0 && game->rays.map_pos < game->width * game->height && game->imap[game->rays.map_pos] == 1)
        {
            game->rays.vertical_x = game->rays.x;
            game->rays.vertical_y = game->rays.y;
            game->rays.distance_vertical = ft_dist(game->player.x, game->player.y, game->rays.vertical_x, game->rays.vertical_y, game->rays.angle);
            game->rays.depth_of_field = 8; // hit wall
        }
        else
        {
            game->rays.x += game->rays.x_offset;
            game->rays.y += game->rays.y_offset;
            game->rays.depth_of_field++;
        }
    }
}

void    rays(t_game *game)
{
    game->rays.angle = game->player.angle - DR * 30;
    if (game->rays.angle < 0)
        game->rays.angle += 2 * PI;
    if (game->rays.angle > 2 * PI)
        game->rays.angle -= 2* PI;
    game->rays.ray = 0;
    int loop = 0;
    int start = 0;
    while (game->rays.ray < 60)
    {
        check_horizontal_lines(game);
        check_vertical_lines(game);
        if (game->rays.distance_vertical < game->rays.distance_horizontal)
        {
            game->rays.x = game->rays.vertical_x;
            game->rays.y = game->rays.vertical_y;
            game->scene.distance = game->rays.distance_vertical;
        }
        if (game->rays.distance_horizontal < game->rays.distance_vertical)
        {
            game->rays.x = game->rays.horizont_x;
            game->rays.y = game->rays.horizont_y;
            game->scene.distance = game->rays.distance_horizontal;
        }
        ft_draw_line(game, game->player.x, game->player.y, game->rays.x, game->rays.y, GREEN);
        // ---------- Draw 3d Walls ----------- //
        float ca = game->player.angle;
        if (ca < 0)
            ca += 2 * PI;
        if (ca > 2 * PI)
            ca -= 2 * PI;
        game->scene.distance = game->scene.distance * cos(ca);
        game->scene.line_height = SQUARE_SIZE * game->screen_height / game->scene.distance;
        if (game->scene.line_height > game->screen_height)
            game->scene.line_height = game->screen_height;
        float lineo = game->screen_height / 2 - game->scene.line_height / 2;
        int how_often = game->screen_width / 60;
        for (int x = 0; x < how_often; x++)
            ft_draw_line(game, start + x , lineo , start + x , game->scene.line_height + lineo , BLACK);
        start += how_often;
        







        // -------- End Drawing ------------ //
        game->rays.angle += DR;
        if (game->rays.angle < 0)
            game->rays.angle += 2 * PI;
        if (game->rays.angle > 2 * PI)
            game->rays.angle -= 2 * PI;
        game->rays.ray++;
    }
}

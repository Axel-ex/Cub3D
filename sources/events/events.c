/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:07:01 by Axel              #+#    #+#             */
/*   Updated: 2024/03/30 15:47:11 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static bool	validate_position(t_point curr, t_point delta_pos)
{
	t_point	next_pos;

	next_pos = (t_point){curr.x + delta_pos.x, curr.y + delta_pos.y};
	if ((next_pos.x < 0 || next_pos.x > SCREEN_W) || next_pos.y < 0
		|| next_pos.y > SCREEN_H)
		return (false);
	if (is_wall(game()->map->arr[(int)next_pos.y][(int)next_pos.x]))
		return (false);
	return (true);
}

void	move_player(t_point delta_pos)
{
	t_point	curr;

	curr = game()->player.pos;
	if (!validate_position(curr, delta_pos))
		return ;
	game()->map->arr[(int)curr.y][(int)curr.x] = FLOOR;
	game()->map->arr[(int)curr.y + (int)delta_pos.y][(int)curr.x
		+ (int)delta_pos.x] = PLAYER;
	game()->player.pos.x += delta_pos.x;
	game()->player.pos.y += delta_pos.y;
	print_player_pos();
}

void	rotate_camera(t_rotation direction)
{
	double	angle;
	t_point	new_dir;

	angle = S_ROTATION * M_PI / 180.0;
	if (direction == LEFT)
		angle = -angle;
	new_dir.x = game()->player.dir.x * cos(angle) - game()->player.dir.y
		* sin(angle);
	new_dir.y = game()->player.dir.x * sin(angle) + game()->player.dir.y
		* cos(angle);
	game()->player.dir = new_dir;
	game()->player.camera.x = -new_dir.y;
	game()->player.camera.y = new_dir.x;
}

int	key_listener(int keycode)
{
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player((t_point){0, 1});
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player((t_point){0, -1});
	else if (keycode == KEY_D)
		move_player((t_point){1, 0});
	else if (keycode == KEY_A)
		move_player((t_point){-1, 0});
	else if (keycode == KEY_RIGHT)
		rotate_camera(RIGHT);
	else if (keycode == KEY_LEFT)
		rotate_camera(LEFT);
	else if (keycode == ESC)
		exit_game(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

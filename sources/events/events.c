/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:07:01 by Axel              #+#    #+#             */
/*   Updated: 2024/04/02 17:13:23 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static bool	validate_position(t_pos curr, t_pos delta_pos)
{
	t_pos	next_pos;

	next_pos = to_map_pos(add_pos(curr, delta_pos));
	if ((next_pos.x < 0 || next_pos.x > SCREEN_W) || next_pos.y < 0
		|| next_pos.y > SCREEN_H)
		return (false);
	if (is_wall(game()->map->arr[(int)next_pos.y][(int)next_pos.x]))
		return (false);
	return (true);
}

void	move_player(t_pos delta_pos)
{
	t_pos	curr;

	curr = game()->player.pos;
	if (!validate_position(curr, delta_pos))
		return ;
	game()->player.prev_pos = curr;
	game()->player.pos = add_pos(curr, delta_pos);
	game()->player.has_moved = true;
	print_player_pos();
}

void	rotate_camera(t_rotation direction)
{
	double	angle;
	t_pos	new_dir;

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
	game()->player.has_moved = true;
}

int	key_listener(int keycode)
{	
	t_player	p;

	p = game()->player;
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(p.dir);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(reverse_dir(p.dir));
	else if (keycode == KEY_D)
		move_player((t_pos){-p.dir.y, p.dir.x});
	else if (keycode == KEY_A)
		move_player((t_pos){p.dir.y, -p.dir.x});
	else if (keycode == KEY_RIGHT)
		rotate_camera(RIGHT);
	else if (keycode == KEY_LEFT)
		rotate_camera(LEFT);
	else if (keycode == ESC)
		exit_game(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

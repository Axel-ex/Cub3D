/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:07:01 by Axel              #+#    #+#             */
/*   Updated: 2024/04/09 17:24:09 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	rotate_camera(t_rotation direction)
{
	double		angle;
	t_player	*p;
	
	p = &game()->player;
	angle = ROTSPEED;
	if (direction == LEFT)
		angle = -angle;
	p->dir.x = p->dir.x * cos(angle) - p->dir.y * sin(angle);
	p->dir.y = p->dir.x * sin(angle) + p->dir.y * cos(angle);
	p->camera.x = p->camera.x * cos(angle) - p->camera.y * sin(angle);
	p->camera.y = p->camera.x * sin(angle) + p->camera.y * cos(angle);
	game()->player.has_moved = 0;
	return (EXIT_SUCCESS);
}

int	key_press(int keycode)
{	
	t_player	p;

	p = game()->player;
	if (keycode == KEY_W)
		game()->player.move_y += 1;
	else if (keycode == KEY_S)
		game()->player.move_y += -1;
	else if (keycode == KEY_D)
		game()->player.move_x += 1;
	else if (keycode == KEY_A)
		game()->player.move_x += -1;
	else if (keycode == KEY_RIGHT)
		game()->player.rotate += 1;
	else if (keycode == KEY_LEFT)
		game()->player.rotate += -1;
	else if (keycode == KEY_ENTER)
	{
		game()->map->render_map = true;
		game()->player.has_moved = 0;
	}
	else if (keycode == ESC)
		exit_game(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	key_release(int keycode)
{
	if (keycode == ESC)
		exit_game(EXIT_SUCCESS);
	if (keycode == KEY_W && game()->player.move_y == 1)
		game()->player.move_y = 0;
	if (keycode == KEY_S && game()->player.move_y == -1)
		game()->player.move_y = 0;
	if (keycode == KEY_A && game()->player.move_x == -1)
		game()->player.move_x += 1;
	if (keycode == KEY_D && game()->player.move_x == 1)
		game()->player.move_x -= 1;
	if (keycode == KEY_LEFT && game()->player.rotate <= 1)
		game()->player.rotate = 0;
	if (keycode == KEY_RIGHT && game()->player.rotate >= -1)
		game()->player.rotate = 0;
	return (EXIT_SUCCESS);
}

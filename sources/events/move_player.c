/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:30:38 by mcarneir          #+#    #+#             */
/*   Updated: 2024/04/12 12:46:01 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"


static int	move_player_forward()
{
	double	new_x;
	double	new_y;

	new_x = game()->player.pos.x + game()->player.dir.x * MOVESPEED;
	new_y = game()->player.pos.y + game()->player.dir.y * MOVESPEED;
	return (validate_move(new_x, new_y));
}

static int	move_player_backward()
{
	double	new_x;
	double	new_y;

	new_x = game()->player.pos.x - game()->player.dir.x * MOVESPEED;
	new_y = game()->player.pos.y - game()->player.dir.y * MOVESPEED;
	return (validate_move(new_x, new_y));
}

static int	move_player_left()
{
	double	new_x;
	double	new_y;

	new_x = game()->player.pos.x + game()->player.dir.y * MOVESPEED;
	new_y = game()->player.pos.y - game()->player.dir.x * MOVESPEED;
	return (validate_move(new_x, new_y));
}

static int	move_player_right()
{
	double	new_x;
	double	new_y;

	new_x = game()->player.pos.x - game()->player.dir.y * MOVESPEED;
	new_y = game()->player.pos.y + game()->player.dir.x * MOVESPEED;
	return (validate_move(new_x, new_y));
}

int	move_player()
{
	int	moved;

	moved = 0;
	if (game()->player.move_y == 1)
		moved += move_player_forward();
	if (game()->player.move_y == -1)
		moved += move_player_backward();
	if (game()->player.move_x == -1)
		moved += move_player_left();
	if (game()->player.move_x == 1)
		moved += move_player_right();
	if (game()->player.rotate == 1)
		moved += rotate_camera(RIGHT);
	if (game()->player.rotate == -1)
		moved += rotate_camera(LEFT);
	return (moved);
}

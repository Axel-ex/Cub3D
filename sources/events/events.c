/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:07:01 by Axel              #+#    #+#             */
/*   Updated: 2024/03/26 18:07:40 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool validate_position(void)
{
	t_player	p;

	p = game()->player;
	if ((p.next_pos.x < 0 || p.next_pos.x > SCREEN_W)
		|| p.next_pos.y < 0 || p.next_pos.y > SCREEN_H )
		return (false);
	if (is_wall(game()->map[p.next_pos.y][p.next_pos.x]))
		return (false);
	return (true);
}

void update_position(void)
{
	t_player	*p;

	p = &game()->player;
	game()->map[p->pos.y][p->pos.x] = FLOOR;
	game()->map[p->next_pos.y][p->next_pos.x] = PLAYER;
	p->pos = p->next_pos;
}

void	move_player(t_point	delta_position)
{
	t_player	*p;
	
	p = &game()->player;
	p->next_pos.x = p->pos.x + delta_position.x;
	p->next_pos.y = p->pos.y + delta_position.y;
	if (validate_position())
		update_position();
}

int	key_listener(int keycode)
{
	if (keycode == KEY_DOWN)
		move_player((t_point){0, 1});
	else if (keycode == KEY_UP)
		move_player((t_point){0, -1});
	else if (keycode == KEY_RIGHT)
		move_player((t_point){1, 0});
	else if (keycode == KEY_LEFT)
		move_player((t_point){-1, 0});
	else if (keycode == ESC)
		exit_game();
	return (EXIT_SUCCESS);
}

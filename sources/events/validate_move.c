/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:48:47 by mcarneir          #+#    #+#             */
/*   Updated: 2024/04/15 15:47:22 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"


static bool	validate_position(t_pos delta_pos)
{
	t_pos	next_pos;
	int		next_y;
	int		next_x;

	next_pos = to_map_pos(delta_pos);
	if ((next_pos.x < 0 || next_pos.x > SCREEN_W) || next_pos.y < 0
		|| next_pos.y > SCREEN_H)
		return(false);
	next_y = (int)next_pos.y;
	next_x = (int)next_pos.x;
	if (is_wall(game()->map_info->arr[next_y][next_x]))
		return(false);
	return(true);
}

int	validate_move(double new_x, double new_y)
{
	int	moved;
	t_pos	curr;
	t_pos 	delta_pos;

	curr = game()->player.pos;
	delta_pos.x = new_x;
	delta_pos.y = new_y;
	moved = 0;
	if (!validate_position(delta_pos))
		return (EXIT_FAILURE);
	game()->player.prev_pos = curr;
	game()->player.pos.x = new_x;
	game()->player.pos.y = new_y;
	moved = 1;
	return(moved);
}

/*int	validate_move(double new_x, double new_y)
{
	int	moved;

	moved = 0;
	game()->player.pos.x = new_x;
	game()->player.pos.y = new_y;
	moved = 1;
	return(moved);
}*/
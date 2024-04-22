/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:48:47 by mcarneir          #+#    #+#             */
/*   Updated: 2024/04/22 13:39:04 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static bool	is_map_cell(t_pos next_pos)
{
	if (game()->map[(int)next_pos.y][(int)next_pos.y])
		return (true);
	return (false);
}

int	validate_move(t_pos next_pos)
{
	t_pos	next;
	int		moved;

	next = to_map_pos(next_pos);
	moved = 0;
	if (is_map_cell(next)
		&& is_wall(game()->map_info->arr[(int)next.y][(int)next.x]))
		return (moved);
	game()->player.pos = next_pos;
	return (++moved);
}

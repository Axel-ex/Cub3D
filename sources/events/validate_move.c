/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:48:47 by mcarneir          #+#    #+#             */
/*   Updated: 2024/04/22 10:59:51 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static bool	is_map_cell(t_pos pos)
{
	if (game()->map[(int)pos.y][(int)pos.x])
		return (true);
	return (false);
}

static int	get_adjacents_walls(void)
{
	int	walls;
	t_pos	p;

	walls = 0;
	p = to_map_pos(game()->player.pos);
	if (is_map_cell((t_pos){p.x + 1, p.y})
		&& is_wall(game()->map[(int)p.y][(int)p.x + 1]))
		walls++;
	if (is_map_cell((t_pos){p.x - 1, p.y})
		&& is_wall(game()->map[(int)p.y][(int)p.x - 1]))
		walls++;
	if (is_map_cell((t_pos){p.x, p.y + 1})
		&& is_wall(game()->map[(int)p.y + 1][(int)p.x]))
		walls++;
	if (is_map_cell((t_pos){p.x, p.y - 1})
		&& is_wall(game()->map[(int)p.y - 1][(int)p.x]))
		walls++;
	return (walls);
}

static bool	is_corner(t_pos p)
{
	t_pos	wall_dist;
	double	i;

	wall_dist = (t_pos){modf(p.x, &i), modf(p.y, &i)};
	printf("%lf, %lf\n", wall_dist.x, wall_dist.y);
	if (get_adjacents_walls() >= 2
		&& ( fabs(wall_dist.x) <= 0.01
		&& fabs(wall_dist.y) <= 0.01))
		return (true);
	return (false);
}

int	validate_move(t_pos next_pos)
{
	t_pos	next;
	int		moved;

	next = to_map_pos(next_pos);
	moved = 0;
	if (is_corner(next))
		return (moved);
	if (is_wall(game()->map_info->arr[(int)next.y][(int)next.x]))
		return (moved);
	game()->player.prev_pos = game()->player.pos;
	game()->player.pos = next_pos;
	return (++moved);
}

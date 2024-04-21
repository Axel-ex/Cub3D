/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:48:47 by mcarneir          #+#    #+#             */
/*   Updated: 2024/04/21 15:57:12 by achabrer         ###   ########.fr       */
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
	t_pos	delta;
	double	i;

	p = to_map_pos(game()->player.pos);
	delta = (t_pos){modf(p.x, &i), modf(p.y, &i)};
	printf("%lf, %lf\n", delta.x, delta.y);
	if (get_adjacents_walls() >= 2
		&& ( fabs(delta.x) <= 0.01
		&& fabs(delta.y) <= 0.01))
		return (true);
	return (false);
}

static bool	validate_position(t_pos delta_pos)
{
	t_pos	next_pos;
	int		next_y;
	int		next_x;

	next_pos = to_map_pos(delta_pos);
	if (is_corner(next_pos))
		return (false);
	if ((next_pos.x < 0 || next_pos.x > SCREEN_W) || next_pos.y < 0
		|| next_pos.y > SCREEN_H)
		return (false);
	next_y = (int)next_pos.y;
	next_x = (int)next_pos.x;
	if (is_wall(game()->map_info->arr[next_y][next_x]))
		return (false);
	return (true);
}

int	validate_move(double new_x, double new_y)
{
	int		moved;
	t_pos	curr;
	t_pos	delta_pos;

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
	return (moved);
}

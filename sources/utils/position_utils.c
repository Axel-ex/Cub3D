/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 07:43:19 by Axel              #+#    #+#             */
/*   Updated: 2024/03/30 15:46:27 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_point	to_screen_pos(t_point pos)
{
	t_point	new;

	new.x = MAP_POS + (TILE_SIZE * pos.x) + ((double)TILE_SIZE / 2);
	new.y = MAP_POS + (TILE_SIZE * pos.y) + ((double)TILE_SIZE / 2);
	return (new);
}

t_point	to_map_pos(t_point pos)
{
	t_point	new;

	new.x = MAP_POS - (pos.x / TILE_SIZE) - ((double)TILE_SIZE / 2);
	new.x = MAP_POS - (pos.y / TILE_SIZE) - ((double)TILE_SIZE / 2);
	return (new);
}

t_point	reverse_dir(t_point dir)
{
	t_point	reversed;

	reversed.x = -dir.x;
	reversed.y = -dir.y;
	return (reversed);
}


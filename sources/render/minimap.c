/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:17:46 by Axel              #+#    #+#             */
/*   Updated: 2024/03/28 08:46:25 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	render_minimap(void)
{
	char	**map;
	int		i;
	int		j;

	i = -1;
	map = game()->map->arr;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_wall(map[i][j]))
				render_square(&game()->screen_buff, (t_square){MAP_POS + (j
						* OFFSET), MAP_POS + (i * OFFSET), OFFSET, BLUE});
			else if (is_floor(map[i][j]))
				render_square(&game()->screen_buff, (t_square){MAP_POS + (j
						* OFFSET), MAP_POS + (i * OFFSET), 20, CYAN});
			else if (is_player(map[i][j]))
				render_square(&game()->screen_buff, (t_square){MAP_POS + (j
						* OFFSET), MAP_POS + (i * OFFSET), 20, RED});
		}
	}
}

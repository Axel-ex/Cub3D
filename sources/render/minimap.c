/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:17:46 by Axel              #+#    #+#             */
/*   Updated: 2024/03/30 15:55:54 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
//
// static void	render_fov(void)
// {
// 	t_point	cam_start_pos;
//
// 	cam_start_pos.x = to_screen_pos(game()->player.pos).x + game()->player.dir.x * 10;
// 	cam_start_pos.y = to_screen_pos(game()->player.pos).y + game()->player.dir.y * 10;
// 	render_line(to_screen_pos(game()->player.pos), game()->player.dir, 30, RED);
// 	render_line(cam_start_pos, game()->player.camera, 20, RED);
// 	render_line(cam_start_pos, reverse_dir(game()->player.camera), 20, RED);
// }

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
						* TILE_SIZE), MAP_POS + (i * TILE_SIZE), TILE_SIZE,
					BLUE});
			else if (is_floor(map[i][j]))
				render_square(&game()->screen_buff, (t_square){MAP_POS + (j
						* TILE_SIZE), MAP_POS + (i * TILE_SIZE), 20, CYAN});
			else if (is_player(map[i][j]))
				render_square(&game()->screen_buff, (t_square){MAP_POS + (j
						* TILE_SIZE), MAP_POS + (i * TILE_SIZE), 20, RED});
		}
	}
	// render_fov();
}

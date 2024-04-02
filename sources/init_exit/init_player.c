/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:29:00 by Axel              #+#    #+#             */
/*   Updated: 2024/04/02 20:28:22 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	set_player_pos(void)
{
	int	i;
	int	j;

	i = -1;
	while (game()->map->arr[++i])
	{
		j = -1;
		while (game()->map->arr[i][++j])
		{
			if (is_player(game()->map->arr[i][j]))
			{
				game()->player.pos = to_screen_pos((t_pos){j, i});
				game()->player.prev_pos = game()->player.pos ;
			}
		}
	}
}

static void	set_player_dir(t_pos pos)
{
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'N')
		game()->player.dir = (t_pos){0, -1};
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'S')
		game()->player.dir = (t_pos){0, 1};
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'W')
		game()->player.dir = (t_pos){-1, 0};
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'E')
		game()->player.dir = (t_pos){1, 0};
}

static void	set_camera_plane(t_pos pos)
{
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'N')
		game()->player.camera = (t_pos){-0.66, 0};
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'S')
		game()->player.camera = (t_pos){0.66, 0};
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'W')
		game()->player.camera = (t_pos){0, -.066};
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'E')
		game()->player.camera = (t_pos){0, 0.66};
}

void	init_player(void)
{
	t_pos	map_pos;

	set_player_pos();
	map_pos = to_map_pos(game()->player.pos);
	set_player_dir(map_pos);
	set_camera_plane(map_pos);
	game()->map->arr[(int)map_pos.y][(int)map_pos.x] = '0';
	game()->player.has_moved = true;
}

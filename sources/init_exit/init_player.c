/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:29:00 by Axel              #+#    #+#             */
/*   Updated: 2024/03/30 15:42:22 by Axel             ###   ########.fr       */
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
				game()->player.pos = (t_point){j, i};
		}
	}
}

static void	set_player_dir(void)
{
	t_point	pos;

	pos = game()->player.pos;
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'N')
		game()->player.dir = (t_point){0, -1};
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'S')
		game()->player.dir = (t_point){0, 1};
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'W')
		game()->player.dir = (t_point){-1, 0};
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'E')
		game()->player.dir = (t_point){1, 0};
}

static void	set_camera_plane(void)
{
	t_point	pos;

	pos = game()->player.pos;
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'N')
		game()->player.camera = (t_point){-0.66, 0};
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'S')
		game()->player.camera = (t_point){0.66, 0};
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'W')
		game()->player.camera = (t_point){0, -0.66};
	if (game()->map->arr[(int)pos.y][(int)pos.x] == 'E')
		game()->player.camera = (t_point){0, 0.66};
}

void	init_player(void)
{
	set_player_pos();
	set_player_dir();
	set_camera_plane();
}

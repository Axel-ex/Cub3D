/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:09:24 by Axel              #+#    #+#             */
/*   Updated: 2024/03/28 13:50:28 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_game(void)
{
	game()->map = ft_calloc(sizeof(t_map), 1);
	if (!game()->map)
		exit_error(ALLOC_ERROR, "map");
	game()->map->arr= ft_calloc(sizeof(char *), 1);
	if (!game()->map->arr)
		exit_error(ALLOC_ERROR, "map array");
	game()->map->no = NULL;
	game()->map->so = NULL;
	game()->map->we = NULL;
	game()->map->ea = NULL;
	game()->map->c = NULL;
	game()->map->f = NULL;
}

void	init_mlx(void)
{
	game()->mlx = mlx_init();
	if (!game()->mlx)
		exit_error("mlx init", NULL);
	game()->mlx_win = mlx_new_window(game()->mlx, SCREEN_W, SCREEN_H, "cub3D");
	if (!game()->mlx_win)
		exit_error("mlx_win init", NULL);
	game()->screen_buff.img = mlx_new_image(game()->mlx, SCREEN_H, SCREEN_W);
	game()->screen_buff.addr = mlx_get_data_addr(game()->screen_buff.img,
			&game()->screen_buff.bbp, &game()->screen_buff.line_length,
			&game()->screen_buff.endian);
}

void	set_player_pos(void)
{
	int	i;
	int	j;

	i = -1;
	while(game()->map->arr[++i])
	{
		j = -1;
		while (game()->map->arr[i][++j])
		{
			if (is_player(game()->map->arr[i][j]))
				game()->player.pos = (t_point){j, i};
		}
	}
}

void	start_game(void)
{
	init_mlx();
	mlx_hook(game()->mlx_win, ON_KEYPRESS, KEYPRESS_MASK, key_listener, NULL);
	mlx_hook(game()->mlx_win, ON_DESTROY, DESTROY_MASK, quit_window, NULL);
	mlx_loop_hook(game()->mlx, render_frame, NULL);
	set_player_pos();
	mlx_loop(game()->mlx);
}

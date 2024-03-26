/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:09:24 by Axel              #+#    #+#             */
/*   Updated: 2024/03/26 13:58:57 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*map[5] = {"111111111111", "100000000N01", "100000000001",
		"111111111111", NULL};

static void	set_hooks(void)
{
	mlx_hook(game()->mlx_win, ON_DESTROY, DESTROY_MASK, quit_window, NULL);
	mlx_hook(game()->mlx_win, ON_KEYPRESS, KEYPRESS_MASK, key_listener, game());
	mlx_loop_hook(game()->mlx, render_frame, NULL);
}

static void	set_player_pos(void)
{
	int	i;
	int	j;

	i = -1;
	while (game()->map[++i])
	{
		j = -1;
		while (game()->map[i][++j])
		{
			if (is_player(game()->map[i][j]))
				game()->player.pos = (t_point){j, i};
		}
	}
}

void	init_game(void)
{
	ft_bzero(game(), sizeof(t_game));
	game()->mlx = mlx_init();
	game()->mlx_win = mlx_new_window(game()->mlx, SCREEN_W, SCREEN_H, "cub3D");
	game()->screen_buff.img = mlx_new_image(game()->mlx, SCREEN_H, SCREEN_W);
	game()->screen_buff.addr = mlx_get_data_addr(game()->screen_buff.img,
			&game()->screen_buff.bbp, &game()->screen_buff.line_length,
			&game()->screen_buff.endian);
	set_hooks();
	//parse_map
	game()->map = map;
	set_player_pos();
}

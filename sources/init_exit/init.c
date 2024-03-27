/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:09:24 by Axel              #+#    #+#             */
/*   Updated: 2024/03/27 14:29:18 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char		*map[5] = {"111111111111", "100000000N01", "100000000001",
			"111111111111", NULL};

static void	init_mlx(void)
{
	game()->mlx = mlx_init();
	if (!game()->mlx)
		exit_error("mlx init", MALLOC_ERROR);
	game()->mlx_win = mlx_new_window(game()->mlx, SCREEN_W, SCREEN_H, "cub3D");
	if (!game()->mlx_win)
		exit_error("mlx_win init", MALLOC_ERROR);
	game()->screen_buff.img = mlx_new_image(game()->mlx, SCREEN_H, SCREEN_W);
	game()->screen_buff.addr = mlx_get_data_addr(game()->screen_buff.img,
			&game()->screen_buff.bbp, &game()->screen_buff.line_length,
			&game()->screen_buff.endian);
	mlx_hook(game()->mlx_win, ON_DESTROY, DESTROY_MASK, quit_window, NULL);
	mlx_hook(game()->mlx_win, ON_KEYPRESS, KEYPRESS_MASK, key_listener, game());
	mlx_loop_hook(game()->mlx, render_frame, NULL);
}

static void	set_player_pos(void)
{
	int	i;
	int	j;

	game()->player.pos = (t_point){0, 0};
	game()->player.next_pos = (t_point){0, 0};
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

void	copy_map(char **map, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
		game()->map[i] = ft_strdup(map[i]);
	game()->map[size - 1] = NULL;
}

void	init_game(void)
{
	ft_bzero(game(), sizeof(t_game));
	//PARSE FILE
	game()->map = (char **)malloc(sizeof(char *) * 5);
	if (!game()->map)
		exit_error("map init", MALLOC_ERROR);
	copy_map(map, 5);
	set_player_pos();
	//MLX_INIT
	init_mlx();
}

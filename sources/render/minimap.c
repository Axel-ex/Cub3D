/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:17:46 by Axel              #+#    #+#             */
/*   Updated: 2024/03/21 12:15:06 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*map[4] = {"111111111111", "100000000N01", "100000000001",
		"111111111111"};

//TODO: check why sometimes a random square is rendered
void	render_minimap(void)
{
	int	i;
	int	j;
	int	offset;

	offset = 20;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_wall(map[i][j]))
				render_square(&game()->screen_buff, (t_square){MAP_POS + (j
						* offset), MAP_POS + (i * offset), 20, BLUE});
			else if (is_floor(map[i][j]))
				render_square(&game()->screen_buff, (t_square){MAP_POS + (j
						* offset), MAP_POS + (i * offset), 20, CYAN});
			else if (is_player(map[i][j]))
				render_square(&game()->screen_buff, (t_square){MAP_POS + (j
						* offset), MAP_POS + (i * offset), 20, RED});
		}
	}
	mlx_put_image_to_window(game()->mlx, game()->mlx_win, game()->screen_buff.img, 0, 0);
}

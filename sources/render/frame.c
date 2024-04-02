/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:49:34 by Axel              #+#    #+#             */
/*   Updated: 2024/04/02 17:12:14 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <stdlib.h>

static void	clear_screen_buffer(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREEN_H)
	{
		j = -1;
		while (++j < SCREEN_W)
			render_pixel((t_pos){j, i}, BLACK);
	}
}

int	render_frame(void)
{
	if (game()->player.has_moved == false)
		return (EXIT_SUCCESS);
	clear_screen_buffer();
	raycaster();
	render_minimap();
	mlx_put_image_to_window(game()->mlx, game()->mlx_win,
		game()->screen_buff.img, 0, 0);
	game()->player.has_moved = false;
	return (EXIT_SUCCESS);
}

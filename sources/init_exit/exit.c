/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:46:56 by Axel              #+#    #+#             */
/*   Updated: 2024/03/26 18:06:10 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <stdlib.h>

void	free_map()
{
	int	i;

	i = -1;
	while (game()->map[++i])
		free(game()->map[i]);
	free(game()->map);
}
void	exit_game(void)
{
	mlx_destroy_image(game()->mlx, game()->screen_buff.img);
	mlx_destroy_window(game()->mlx, game()->mlx_win);
	free_map();
	exit(EXIT_SUCCESS);
}

int	quit_window(void)
{
	exit_game();
	return (EXIT_SUCCESS);
}

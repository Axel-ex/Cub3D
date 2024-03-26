/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:46:56 by Axel              #+#    #+#             */
/*   Updated: 2024/03/26 11:04:55 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <stdlib.h>

void	exit_game(void)
{
	mlx_destroy_image(game()->mlx, game()->screen_buff.img);
	mlx_destroy_window(game()->mlx, game()->mlx_win);
	exit(EXIT_SUCCESS);
}

int	quit_window(void)
{
	exit_game();
	return (EXIT_SUCCESS);
}

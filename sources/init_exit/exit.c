/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:46:56 by Axel              #+#    #+#             */
/*   Updated: 2024/03/27 15:53:42 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <stdlib.h>

void	exit_error(char *err_msg, int exit_status)
{
	printf("%sError%s: ", ANSIRED, RESET);
	printf("%s", err_msg);
	exit_game(exit_status);
}

void	exit_game(int exit_status)
{
	if (game()->screen_buff.img)
		mlx_destroy_image(game()->mlx, game()->screen_buff.img);
	if (game()->mlx_win)
		mlx_destroy_window(game()->mlx, game()->mlx_win);
	if (game()->mlx)
	{
		mlx_destroy_display(game()->mlx);
		free(game()->mlx);
	}
	if (game()->map)
		free_map();
	exit(exit_status);
}

int	quit_window(void)
{
	exit_game(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:46:56 by Axel              #+#    #+#             */
/*   Updated: 2024/03/28 09:24:14 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	exit_error(char *err_msg, char *var)
{
	printf("%sError%s: ", ANSIRED, RESET);
	if (var)
		printf("%s: ", var);
	printf("%s", err_msg);
	exit_game(EXIT_FAILURE);
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

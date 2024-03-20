/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:46:56 by Axel              #+#    #+#             */
/*   Updated: 2024/03/20 23:24:21 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	exit_game()
{
	mlx_destroy_image(game()->mlx, game()->pixel->img);
	mlx_destroy_window(game()->mlx, game()->mlx);
	free(game()->pixel);
}

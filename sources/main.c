/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:30:10 by Axel              #+#    #+#             */
/*   Updated: 2024/03/21 08:30:29 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	init_game();
	render_minimap();
	mlx_loop(game()->mlx);
	exit_game();
	return (EXIT_SUCCESS);
}

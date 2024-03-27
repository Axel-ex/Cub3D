/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:30:10 by Axel              #+#    #+#             */
/*   Updated: 2024/03/27 09:12:38 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include <stdlib.h>

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	
	if (argc < 2)
		exit_error(USAGE, EXIT_FAILURE);
	init_game();
	mlx_loop(game()->mlx);
	return (EXIT_SUCCESS);
}

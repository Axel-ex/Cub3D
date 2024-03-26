/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:30:10 by Axel              #+#    #+#             */
/*   Updated: 2024/03/26 15:08:12 by Axel             ###   ########.fr       */
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
	int	error;
	(void)argc;
	(void)argv;
	
	error = init_game();
	if (error != EXIT_SUCCESS)
		return (error);
	mlx_loop(game()->mlx);
	return (EXIT_SUCCESS);
}

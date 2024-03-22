/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:30:10 by Axel              #+#    #+#             */
/*   Updated: 2024/03/22 13:52:39 by achabrer         ###   ########.fr       */
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
	// render_square(&game()->screen_buff, (t_square){50, 50, 50, RED});
	// mlx_put_image_to_window(game()->mlx, game()->mlx_win, game()->screen_buff.img, 0, 0);
	mlx_loop(game()->mlx);
	exit_game();
	return (EXIT_SUCCESS);
}

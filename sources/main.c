/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:30:10 by Axel              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/22 13:42:24 by Axel             ###   ########.fr       */
=======
/*   Updated: 2024/03/22 13:52:39 by achabrer         ###   ########.fr       */
>>>>>>> 2f12dda3141b95aaa3021b5b2d8ec94ab02854b0
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
<<<<<<< HEAD
	// render_minimap();
	render_square(&game()->screen_buff, (t_square){50, 50, 50, RED});
	mlx_put_image_to_window(game()->mlx, game()->mlx_win, game()->screen_buff.img, 0, 0);
=======
	render_minimap();
	// render_square(&game()->screen_buff, (t_square){50, 50, 50, RED});
	// mlx_put_image_to_window(game()->mlx, game()->mlx_win, game()->screen_buff.img, 0, 0);
>>>>>>> 2f12dda3141b95aaa3021b5b2d8ec94ab02854b0
	mlx_loop(game()->mlx);
	exit_game();
	return (EXIT_SUCCESS);
}

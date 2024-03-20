/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:30:10 by Axel              #+#    #+#             */
/*   Updated: 2024/03/20 23:39:28 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_game	*game()
{
	static t_game game;

	return (&game);
}

void test()
{
	t_data	img;

	img.img = mlx_new_image(game()->mlx, SCREEN_W, SCREEN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	render_square(&img, 50, 50, 100, GREEN);
}

//TODO: Try to have the img declared on the stack
int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	init_game();
	// render_square(&game()->pixel, 50, 50, 100, create_trgb(0, 155, 0, 150));
	draw_minimap();
	// test();
	mlx_loop(game()->mlx);
	exit_game();

	return (EXIT_SUCCESS);
}

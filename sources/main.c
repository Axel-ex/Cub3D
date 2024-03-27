/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:30:10 by Axel              #+#    #+#             */
/*   Updated: 2024/03/27 17:31:18 by mcarneir         ###   ########.fr       */
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
	if (argc != 2 || check_file(argv[1], ".cub") != 0)
	{
		ft_putstr_fd("Invalid map\n", STDERR_FILENO);
		return (1);
	}
	//init_game();
	if (map_validation(argv[1]) != 0)
	{
		return (1);
		ft_putstr_fd("Invalid map\n", STDERR_FILENO);
	}
	//render_minimap();
	// render_square(&game()->screen_buff, (t_square){50, 50, 50, RED});
	// mlx_put_image_to_window(game()->mlx, game()->mlx_win, game()->screen_buff.img, 0, 0);
	//mlx_loop(game()->mlx);
	//exit_game();
	return (EXIT_SUCCESS);
}

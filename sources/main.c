/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:30:10 by Axel              #+#    #+#             */
/*   Updated: 2024/03/28 11:35:46 by Axel             ###   ########.fr       */
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
	if (argc != 2)
		exit_error(USAGE, NULL);
	init_game();
	parse_file(argv[1]);
	start_game();
	return (EXIT_SUCCESS);
}

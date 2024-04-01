/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:09 by Axel              #+#    #+#             */
/*   Updated: 2024/04/01 14:51:08 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	print_map(t_point err_pos)
{
	char	**map;
	int		i;
	int		j;

	map = game()->map->arr;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (i == err_pos.x && j == err_pos.y)
				printf("%s%c%s", ANSIRED, map[i][j], RESET);
			else
				printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

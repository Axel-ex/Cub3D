/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:09 by Axel              #+#    #+#             */
/*   Updated: 2024/03/28 11:38:34 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	print_map(int i_pos, int j_pos)
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
			if (i == i_pos && j == j_pos)
				printf("%s%c%s", ANSIRED, map[i][j], RESET);
			else
				printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

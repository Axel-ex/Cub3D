/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:17:46 by Axel              #+#    #+#             */
/*   Updated: 2024/03/20 23:40:44 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char		*map[4] = {"111111111111", "100000000001", "100000000001",
			"111111111111"};

void	draw_minimap()
{
	int	i;
	int	j;
	int	offset;

	offset = 20;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				render_square(&game()->pixel, MAP_POS + (j * offset), MAP_POS + (i
						* offset), 20, RED);
			else if (map[i][j] == '0')
				render_square(&game()->pixel, MAP_POS + (j * offset), MAP_POS + (i
						* offset), 20, GREEN);
			j++;
		}
		i++;
	}
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:17:46 by Axel              #+#    #+#             */
/*   Updated: 2024/03/21 08:54:15 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*map[4] = {"111111111111", "100000000001", "100000000001",
		"111111111111"};

void	render_minimap(void)
{
	int	i;
	int	j;
	int	offset;

	offset = 20;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				render_square(&game()->screen_buff, (t_square){MAP_POS + (j
						* offset), MAP_POS + (i * offset), 20, RED});
			else if (map[i][j] == '0')
				render_square(&game()->screen_buff, (t_square){MAP_POS + (j
						* offset), MAP_POS + (i * offset), 20, GREEN});
			else if (is_player(map[i][j]))
				render_square(&game()->screen_buff, (t_square){MAP_POS + (j
						* offset), MAP_POS + (i * offset), 20, GREEN});
		}
	}
}

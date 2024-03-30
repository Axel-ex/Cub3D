/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:09 by Axel              #+#    #+#             */
/*   Updated: 2024/03/30 15:47:24 by Axel             ###   ########.fr       */
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

void	print_player_pos(void)
{
	t_player	p;

	p = game()->player;
	printf("Position on map: {%lf, %lf}\n", p.pos.x, p.pos.y);
	printf("position on screen: {%lf, %lf\n}", to_screen_pos(p.pos).x,
		to_screen_pos(p.pos).y);
	printf("Direction: {%lf, %lf}\n", p.dir.x, p.dir.y);
	printf("\n");
}

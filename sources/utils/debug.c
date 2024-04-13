/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:09 by Axel              #+#    #+#             */
/*   Updated: 2024/04/12 13:07:40 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	print_map(t_pos err_pos)
{
	int		i;
	int		j;

	i = -1;
	while (game()->map[++i])
	{
		j = -1;
		while (game()->map[i][++j])
		{
			if (i == err_pos.x && j == err_pos.y)
				printf("%s%c%s", ANSIRED, game()->map[i][j], RESET);
			else
				printf("%c", game()->map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void	print_player_pos(void)
{
	t_player	p;

	p = game()->player;
	printf("Position on screen: {%lf, %lf}\n", p.pos.x, p.pos.y);
	printf("position on screen: {%lf, %lf}\n", to_map_pos(p.pos).x,
		to_map_pos(p.pos).y);
	printf("Direction: {%lf, %lf}\n", p.dir.x, p.dir.y);
	printf("\n");
}

void	print_ray_info(t_ray *ray)
{
	printf("wall_x: %lf\n", ray->wall_x);
}

void	print_text_info(t_text_info	*info, t_ray *ray, int	curr_x)
{
	if (ray->wall_dist > RENDER_DIST)
		return ;
	printf("%s%d%s\n", ANSIRED, curr_x, RESET);
	print_ray_info(ray);
	printf("x: %d\n", info->x);
	printf("step: %lf\n", info->step);
	printf("pos: %lf\n", info->pos);
	printf("\n\n");
}

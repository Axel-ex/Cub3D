/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:44:32 by Axel              #+#    #+#             */
/*   Updated: 2024/04/10 09:27:49 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//TODO: load textures
//
static void	load_color(char *str, char type)
{
	int		red;
	int		green;
	int		blue;
	int		*color;
	char	**colors;

	if (type == 'c')
		color = &game()->map->c;
	else
		color = &game()->map->f;
	colors = ft_split(str, ',');
	red = ft_atoi(colors[0]);
	green = ft_atoi(colors[1]);
	blue = ft_atoi(colors[2]);
	*color = create_trgb(0, red, green, blue);
	free_matrix(colors);
}

void	load_textures(void)
{
	game()->map->arr = game()->map_info->arr;
	load_color(game()->map_info->f, 'f');
	load_color(game()->map_info->c, 'c');
}

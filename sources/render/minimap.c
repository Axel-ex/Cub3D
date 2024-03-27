/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:17:46 by Axel              #+#    #+#             */
/*   Updated: 2024/03/27 19:12:27 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// void	render_minimap(void)
// {
// 	int	i;
// 	int	j;
// 	int	offset;
//
// 	offset = 20;
// 	i = 0;
// 	j = 0;
// 	while (game()->map[i])
// 	{
// 		j = 0;
// 		while (game()->map[i][j])
// 		{
// 			if (is_wall(game()->map[i][j]))
// 				render_square(&game()->screen_buff, (t_square){MAP_POS + (j
// 						* offset), MAP_POS + (i * offset), 20, BLUE});
// 			else if (is_floor(game()->map[i][j]))
// 				render_square(&game()->screen_buff, (t_square){MAP_POS + (j
// 						* offset), MAP_POS + (i * offset), 20, CYAN});
// 			else if (is_player(game()->map[i][j]))
// 				render_square(&game()->screen_buff, (t_square){MAP_POS + (j
// 						* offset), MAP_POS + (i * offset), 20, RED});
// 			j++;
// 		}
// 		i++;
// 	}
// }

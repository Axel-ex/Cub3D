/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:34:25 by Axel              #+#    #+#             */
/*   Updated: 2024/03/28 09:11:19 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_map(void)
{
	free_matrix(game()->map->arr);
	free(game()->map->no);
	free(game()->map->so);
	free(game()->map->we);
	free(game()->map->ea);
	free(game()->map->c);
	free(game()->map->f);
	free(game()->map);
}

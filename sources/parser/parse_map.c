/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:50:56 by Axel              #+#    #+#             */
/*   Updated: 2024/03/27 23:52:07 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	**parse_map(int fd)
{
	char	*line;
	char	**map;
	
	map = ft_calloc(sizeof(char *), 1);
	if (!map)
		exit_error("read_map alloc", NULL);
	*map = NULL;
	while(42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		matrix_append(&map, line);
		free(line);
	}
	return (map);
}


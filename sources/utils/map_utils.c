/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:50:10 by Axel              #+#    #+#             */
/*   Updated: 2024/03/28 08:57:15 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == PLAYER);
}

bool	is_floor(char c)
{
	return (c == FLOOR);
}

bool	is_wall(char c)
{
	return (c == WALL);
}

bool	ft_is_digit(char *str)
{
	int	i;
	
	i = -1;
	while(str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	is_map_row(char *line)
{
	int	i;

	i = -1;
	if (line[0] == '\n')
		return (false);
	while (line[++i])
	{
		if (ft_isdigit(line[i]) || line[i] == ' ' || line[i] == '\n'
			|| is_player(line[i]))
			continue ;
		else
			return (false);
	}
	return (true);
}

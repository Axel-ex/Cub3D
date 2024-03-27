/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:50:10 by Axel              #+#    #+#             */
/*   Updated: 2024/03/27 17:18:34 by mcarneir         ###   ########.fr       */
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
	
	i = 0;
	while(str[i++])
	{
		if (!ft_isdigit(str[i]))
			return (false);
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:35:24 by mcarneir          #+#    #+#             */
/*   Updated: 2024/04/19 16:08:01 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	initialize_chars(char **chars)
{
	chars[0] = "NO";
	chars[1] = "SO";
	chars[2] = "WE";
	chars[3] = "EA";
	chars[4] = "F";
	chars[5] = "C";
	chars[6] = NULL;
}

bool	check_player(char **map)
{
	int		i;
	int		j;
	int		p;

	i = 0;
	p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
				p += 1;
			j++;
		}
		i++;
	}
	if (p != 1)
		return (false);
	else
		return (true);
}


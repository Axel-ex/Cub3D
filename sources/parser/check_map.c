/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:50:56 by Axel              #+#    #+#             */
/*   Updated: 2024/03/28 12:44:26 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//checks if only ones (ignoring the last new line char)
static bool	only_ones(char *str)
{
	size_t i;

	i = -1;
	while(str[++i])
	{
		if (str[i] != '1' && i != ft_strlen(str) - 1)
			return (false);
	}
	return (true);
}

//checks if: 
//- first and last line are only 1
//- curr row is bigger then the top one and if we passed the edge of the top_row (should be 1)
//- same but with the bottom row
static bool	is_closed_map(char **map, size_t i)
{
	char	*curr_row;
	char	*top_row;
	char	*bott_row;
	size_t	j;
	
	curr_row = map[i];
	top_row = map[i -1];
	bott_row = map[i + 1];
	if (only_ones(curr_row) && (i == 0 || i == get_matrix_len(map) - 1))
		return (true);
	j = -1;
	while (curr_row[++j] && curr_row[j] != '\n')
	{
		if (top_row && ft_strlen(curr_row) > ft_strlen(top_row)
			&& j > ft_strlen(top_row) - 1 && curr_row[j] != '1')
		{
			print_map((t_point){i, j});
			return (false);
		}
		if (bott_row && ft_strlen(curr_row) > ft_strlen(bott_row)
			&& j > ft_strlen(bott_row) - 1 && curr_row[j] != '1')
		{
			print_map((t_point){i, j});
			return (false);
		}
	}
	return (true);
}

static bool has_invalid_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (is_wall(str[i]) || is_player(str[i]) || is_floor(str[i])
			|| str[i] == ' ')
			continue ;
		else
			return (true);
	}
	return (false);
}

void	check_map(char	**map)
{
	size_t	i;

	i = -1;
	while (map[++i])
	{
		if (map[i][0] == '\0')
			exit_error(NL_IN_MAP, INVALID_MAP);
		if (!is_closed_map(map, i))
			exit_error(INVALID_WALLS, INVALID_MAP);
		if (has_invalid_char(map[i]))
			exit_error(INVALID_CHAR, INVALID_MAP);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:28:58 by Axel              #+#    #+#             */
/*   Updated: 2024/04/24 15:27:45 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

size_t	get_matrix_len(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	matrix_append(char ***matrix_ptr, char *to_append)
{
	char	**matrix;
	char	**new_matrix;
	int		i;

	matrix = *matrix_ptr;
	new_matrix = ft_calloc(sizeof(char *), get_matrix_len(matrix) + 2);
	if (!new_matrix)
		exit_error("matrix append", ALLOC_ERROR);
	i = 0;
	while (matrix[i])
	{
		new_matrix[i] = ft_strtrim(matrix[i], "\n");
		i++;
	}
	new_matrix[i++] = ft_strtrim(to_append, "\n");
	new_matrix[i] = NULL;
	free_matrix(matrix);
	*matrix_ptr = new_matrix;
}

void	trim_matrix(char **map)
{
	int		i;
	int		j;
	char	**new_matrix;

	i = get_col_size();
	j = 0;
	while (map[i] == NULL)
		i--;
	new_matrix = ft_calloc(get_col_size() - i, sizeof(char *));
	if (!new_matrix)
		exit_error(ALLOC_ERROR, INVALID_MAP);
	while(j < i)
	{
		matrix_append(&new_matrix, map[j]);
		j++;
	}
	new_matrix[j] = NULL;
	free_matrix(map);
	game()->map_info->arr = new_matrix;
}

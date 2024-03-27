/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:28:58 by Axel              #+#    #+#             */
/*   Updated: 2024/03/27 22:33:35 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	free_matrix(char **matrix)
{
	int	i = -1;

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
		return ;
		// exit_error("matrix append", MALLOC_ERROR);
	i = 0;
	while (matrix[i])
	{
		new_matrix[i] = ft_strdup(matrix[i]);
		i++;
	}
	new_matrix[i++] = ft_strdup(to_append);
	new_matrix[i] = NULL;
	free_matrix(matrix);
	*matrix_ptr = new_matrix;
}

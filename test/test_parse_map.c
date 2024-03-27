/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:28:58 by Axel              #+#    #+#             */
/*   Updated: 2024/03/27 17:38:07 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include <fcntl.h>

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


char	**read_map(int fd)
{
	char	*line;
	char	**map;
	
	map = ft_calloc(sizeof(char *), 1);
	if (!map)
		return (NULL);
		// exit_error("read_map", MALLOC_ERROR);
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
//
// void	parse_map(int fd)
// {
//
//
// }

int	main(void)
{
	int	fd;
	char	**map;
	
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return 1;
	map = read_map(fd);
	
	int	i = -1;
	while(map[++i])
		printf("%s", map[i]);
	free_matrix(map);
}

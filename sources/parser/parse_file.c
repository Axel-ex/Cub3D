/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:05:41 by mcarneir          #+#    #+#             */
/*   Updated: 2024/04/13 20:19:53 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	check_file(char *str, char *ext, char *alt)
{
	int		fd;
	char	*substr;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		exit_error(FILE_NT_FOUND, str);
	}
	substr = ft_strrchr(str, '.');
	if (!substr)
		exit_error(INVALID_EXT, str);
	if (!ft_strncmp(substr, ext, 4) || !ft_strncmp(substr, alt, 4))
		return ;
	close(fd);
	exit_error(INVALID_EXT, str);
}

// Split the string by the ',' and check if it is a valid value
static void	check_color(char *str)
{
	char	**color;
	char	*trimmed;
	int		i;

	color = ft_split(str, ',');
	if (!color || !color[0] || !color[1] || !color[2] || color[3])
	{
		free_matrix(color);
		exit_error(INVALID_COLOR, str);
	}
	i = -1;
	while (color[++i])
	{
		trimmed = ft_strtrim(color[i], " \t\n\r\v\f");
		if (!ft_is_digit(trimmed) || ft_atoi(trimmed) < 0
			|| ft_atoi(trimmed) > 255 || ft_strlen(trimmed) > 3)
		{
			free_matrix(color);
			free(trimmed);
			exit_error(INVALID_COLOR, str);
			free(trimmed);
		}
		free(trimmed);
	}
	free_matrix(color);
}

static void	check_elements(void)
{
	if (!game()->map_info->no || !game()->map_info->so || !game()->map_info->we
		|| !game()->map_info->ea || !game()->map_info->c
		|| !game()->map_info->f)
		exit_error(MISS_TEXTURE, NULL);
	check_file(game()->map_info->no, ".xpm", ".png");
	check_file(game()->map_info->so, ".xpm", ".png");
	check_file(game()->map_info->we, ".xpm", ".png");
	check_file(game()->map_info->ea, ".xpm", ".png");
	check_color(game()->map_info->c);
	check_color(game()->map_info->f);
}

static void	parse_elements(char *str)
{
	char	*chars[7] = {"NO", "SO", "WE", "EA", "F", "C", NULL};

	str = trim_elements(str, chars);
	if (str[0] == 'N' && str[1] == 'O')
		game()->map_info->no = cleaner(&str[2]);
	else if (str[0] == 'S' && str[1] == 'O')
		game()->map_info->so = cleaner(&str[2]);
	else if (str[0] == 'W' && str[1] == 'E')
		game()->map_info->we = cleaner(&str[2]);
	else if (str[0] == 'E' && str[1] == 'A')
		game()->map_info->ea = cleaner(&str[2]);
	else if (str[0] == 'C' && str[1] == ' ')
		game()->map_info->c = cleaner(&str[1]);
	else if (str[0] == 'F' && str[1] == ' ')
		game()->map_info->f = cleaner(&str[1]);
	else if (is_map_row(str) || (str[0] == '\n' && game()->map_info->arr[0]))
		matrix_append(&game()->map_info->arr, str);
	order_check(str);
}

void	parse_file(char *file)
{
	char	*line;
	int		fd;

	check_file(file, ".cub", ".cub");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(FILE_NT_FOUND, file);
	line = get_next_line(fd);
	while (line)
	{
		parse_elements(line);
		free(line);
		line = get_next_line(fd);
	}
	check_elements();
	check_map(game()->map_info->arr);
}

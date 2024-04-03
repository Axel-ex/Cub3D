/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:05:41 by mcarneir          #+#    #+#             */
/*   Updated: 2024/04/02 22:49:45 by Axel             ###   ########.fr       */
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

//Split the string by the ',' and check if it is a valid value
static void	check_color(char *str)
{
	char **color;
	char *trimmed;
	int	i;

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
		if (!ft_is_digit(trimmed) || ft_atoi(trimmed) < 0 || ft_atoi(trimmed) > 255
				|| ft_strlen(trimmed) > 3)
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

//Check if the textures end with .xpm or .png and if the RGB values of C and F are valid
static void	check_elements()
{
	if (!game()->map->no || !game()->map->so || !game()->map->we 
		|| !game()->map->ea || !game()->map->c || !game()->map->f)
		exit_error(MISS_TEXTURE, NULL);
	check_file(game()->map->no, ".xpm", ".png");
	check_file(game()->map->so, ".xpm", ".png");
	check_file(game()->map->we, ".xpm", ".png");
	check_file(game()->map->ea, ".xpm", ".png");
	check_color(game()->map->c);
	check_color(game()->map->f);
}

//Store the paths of the textures and the RGB values in our struct
static void	parse_elements(char *str)
{
	
	char *chars[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	str = trim_elements(str, chars);
	if (str[0] == 'N' && str[1] == 'O')
		game()->map->no = cleaner(&str[2]);
	else if (str[0] == 'S' && str[1] == 'O')
		game()->map->so = cleaner(&str[2]);
	else if (str[0] == 'W' && str[1] == 'E')
		game()->map->we = cleaner(&str[2]);
	else if (str[0] == 'E' && str[1] == 'A')
		game()->map->ea = cleaner(&str[2]);
	else if (str[0] == 'C' && str[1] == ' ')
		game()->map->c = cleaner(&str[1]);
	else if (str[0] == 'F' && str[1] == ' ')
		game()->map->f = cleaner(&str[1]);
	else if (is_map_row(str) || (str[0] == '\n' && game()->map->arr[0]))
		matrix_append(&game()->map->arr, str);
	order_check(str);
}

void	parse_color(char *str, char type)
{
	int		red;
	int		green;
	int		blue;
	int		*color;
	char	**colors;

	if (type == 'c')
		color = &game()->map->ceiling_col;
	else
		color = &game()->map->floor_col;
	colors = ft_split(str, ',');
	red = ft_atoi(colors[0]);
	green = ft_atoi(colors[1]);
	blue = ft_atoi(colors[2]);
	*color = create_trgb(0, red, green, blue);
}

void	parse_file(char	*file)
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
	check_map(game()->map->arr);
	parse_color(game()->map->c, 'c');
	parse_color(game()->map->f, 'f');
}

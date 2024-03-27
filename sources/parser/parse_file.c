/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:05:41 by mcarneir          #+#    #+#             */
/*   Updated: 2024/03/27 23:54:54 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//NOTE: I refactored the code using the exit_error(). It's handier since we 
//don't have to deal with return value, the function simply exit with the
//appropriated message (define in cub3D_utils.h)

//file extension checker
void	check_file(char *str)
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
	if (!ft_strncmp(substr, ".xmp", 4) || !ft_strncmp(substr, ".png", 4))
		return;
	close(fd);
	exit_error(INVALID_EXT, str);
}

//Split the string by the ',' and check if it is a valid value
static void	check_color(char *str)
{
	char **color;
	int	i;

	color = ft_split(str, ',');
	if (!color || !color[0] || !color[1] || !color[2] || color[3])
	{
		free_array(color);
		exit_error(INVALID_COLOR, str);
	}
	i = 0;
	while (color[i++])
	{
		if (!ft_is_digit(color[i]) || ft_atoi(color[i]) < 0 || ft_atoi(color[i]) > 255
				|| ft_strlen(color[i]) > 3)
		{
			free_array(color);
			exit_error(INVALID_COLOR, str);
		}
	}
	free_array(color);
}

//Check if the textures end with .xpm or .png and if the RGB values of C and F are valid
static void	check_elements()
{
	if (!game()->map->no || !game()->map->so || !game()->map->we 
		|| !game()->map->ea || !game()->map->c || !game()->map->f)
		exit_error(MISS_TEXTURE, NULL);
	check_file(game()->map->no);
	check_file(game()->map->so);
	check_file(game()->map->we);
	check_file(game()->map->ea);
	check_color(game()->map->c);
	check_color(game()->map->f);
}

//Store the paths of the textures and the RGB values in our struct
static void	parse_elements(char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		game()->map->no = ft_substr(str, 3, (ft_strlen(str) - 4));
	else if (str[0] == 'S' && str[1] == 'O')
		game()->map->so = ft_substr(str, 3, (ft_strlen(str) - 4));
	else if (str[0] == 'W' && str[1] == 'E')
		game()->map->we = ft_substr(str, 3, (ft_strlen(str) - 4));
	else if (str[0] == 'E' && str[1] == 'A')
		game()->map->ea = ft_substr(str, 3, (ft_strlen(str) - 4));
	else if (str[0] == 'C' && str[1] == ' ')
		game()->map->c = ft_substr(str, 2, (ft_strlen(str) - 3));
	else if (str[0] == 'F' && str[1] == ' ')
		game()->map->f = ft_substr(str, 2, (ft_strlen(str) - 3));
	// else if (is_map(str))
	// 	parse_map();
}

//NOTE: Renamed the function 
void	parse_file(char	*file)
{
	char	*line;
	int		fd;

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
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:05:41 by mcarneir          #+#    #+#             */
/*   Updated: 2024/03/27 17:45:53 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//file extension checker
int	check_file(char *str, char *ext)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("\033[1;31mError\033[0m\n", STDERR_FILENO);
		close(fd);
		return (1);
	}
	str = ft_strrchr(str, '.');
	if (!str)
	{
		ft_putstr_fd("\033[1;31mError\033[0m\n", STDERR_FILENO);
		return (1);
	}
	if (ft_strncmp(str, ext, 4) != 0)
	{
		ft_putstr_fd("\033[1;31mError\033[0m\n", STDERR_FILENO);
		return (1);
	}
	close(fd);
	return (0);
}

//Split the string by the ',' and check if it is a valid value
static bool	check_color(char *str)
{
	char **color;
	int	i;

	color = ft_split(str, ',');
	if (!color || !color[0] || !color[1] || !color[2] || color[3])
	{
		free_array(color);
		return (false);
	}
	i = 0;
	while (color[i++])
	{
		if (!ft_is_digit(color[i]) || ft_atoi(color[i]) < 0 || ft_atoi(color[i]) > 255
				|| ft_strlen(color[i]) > 3)
		{
			free_array(color);
			return (false);
		}
	}
	free_array(color);
	return (true);
}

//Store the paths of the textures and the RGB values in our struct
static void	identify_elements(char *str)
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
}


//Check if the textures end with .xpm or .png and if the RGB values of C and F are valid
static bool	check_elements()
{
	if (!game()->map->no || !game()->map->so || !game()->map->we 
		|| !game()->map->ea || !game()->map->c || !game()->map->f)
		return (false);
	if (check_file(game()->map->no, ".xpm") || check_file(game()->map->no, ".png") 
		|| check_file(game()->map->so, ".xpm") || check_file(game()->map->so, ".png")
		|| check_file(game()->map->we, ".xpm") || check_file(game()->map->we, ".png")
		|| check_file(game()->map->ea, ".xpm") || check_file(game()->map->ea, ".png")
		|| !check_color(game()->map->c) || !check_color(game()->map->f))
		return (false);
	return (true);
}

bool	map_validation(char *file)
{
	char *line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		identify_elements(line);
		free(line);
		line = get_next_line(fd);
	}
	if (!check_elements())
		return (false);
	return (true);
}

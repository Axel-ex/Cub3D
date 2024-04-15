/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:19:39 by mcarneir          #+#    #+#             */
/*   Updated: 2024/04/15 15:57:42 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (0);
}

bool	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (true);
	return (false);
}

char	*trim_elements(char *str, char **chars)
{
	char	*substring;
	char	*new;
	int		i;

	i = 0;
	while (chars[i])
	{
		substring = ft_strstr(str, chars[i]);
		if (substring)
		{
			new = ft_substr(substring, 0, ft_strlen(substring));
			return(new);
		}
		i++;
	}
	return (str);
}

char	*cleaner(char *str)
{
	int		i;
	int		j;
	char	*new;

	if (!str && !*str)
		return (NULL);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	j = ft_strlen(str) - 1;
	while (ft_isspace(str[j]))
		j--;
	if (str[j] == '\n')
		j--;
	new = ft_substr(str, i, j - i + 1);
	return (new);
}

void	order_check(char *str)
{
	if (game()->map_info->arr[0] != NULL)
	{
		if ((game()->map_info->no == NULL || game()->map_info->no[0] == '\0')
			&& (game()->map_info->so == NULL
				|| game()->map_info->so[0] == '\0')
			&& (game()->map_info->we == NULL
				|| game()->map_info->we[0] == '\0')
			&& (game()->map_info->ea == NULL
				|| game()->map_info->ea[0] == '\0')
			&& (game()->map_info->f == NULL
				|| game()->map_info->f[0] == '\0')
			&& (game()->map_info->c == NULL
				|| game()->map_info->c[0] == '\0'))
		{
			exit_error(MAP_FIRST, str);
		}
	}
}

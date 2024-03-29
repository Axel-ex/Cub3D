/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:19:39 by mcarneir          #+#    #+#             */
/*   Updated: 2024/03/29 16:44:30 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

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
	if (c == '\t' || c == '\n' || c == '\v' 
		|| c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}


//Removes all leading whitespaces
char *trim_elements(char *str, char **chars)
{
    char *substring;
    char *new;
    int i = 0;

    while (chars[i])
    {
        substring = ft_strstr(str, chars[i]);
        if (substring)
        {
            new = ft_substr(substring, 0, ft_strlen(substring));
            return (new);
        }
        i++;
    }
    return (str);
}

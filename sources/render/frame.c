/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:49:34 by Axel              #+#    #+#             */
/*   Updated: 2024/03/26 14:17:52 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <stdlib.h>

int	render_frame(void)
{
	render_minimap();
	mlx_put_image_to_window(game()->mlx, game()->mlx_win,
		game()->screen_buff.img, 0, 0);
	return (EXIT_SUCCESS);
}

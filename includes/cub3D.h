/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:51:53 by Axel              #+#    #+#             */
/*   Updated: 2024/03/20 23:24:40 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"

#define SCREEN_W	600
#define SCREEN_H	600
#define MAP_POS		50

/**
 * @brief 
 * 
 * takes int between 0 and 255 and creates trgb color by bitshifting and bitwise | op 
 * see below for exemple.
 *
 * @return color code
 */
int	create_trgb(int t, int r, int g, int b);

#define RED		create_trgb(0, 255, 0, 0)
#define GREEN	create_trgb(0, 0, 255, 0)
#define BLUE	create_trgb(0, 0, 0, 255)

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_player
{
	//sprites
	//positon
}	t_player;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	t_data	*pixel;
	//textures
	//player
}	t_game;

/**
 * @brief Return a static instance of the game struct.
 * 
 * @return t_game *
 */
t_game *game();

//INIT_EXIT
void	init_game();
void	exit_game();

//RENDER
//shapes.c
void	render_pixel(t_data *data, int x, int y, int color);
void	render_square(t_data *img, int x, int y, int width, int color);

//color.c
int	create_trgb(int t, int r, int g, int b);

//minimap.c
void	draw_minimap();

#endif

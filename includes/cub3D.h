/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:51:53 by Axel              #+#    #+#             */
/*   Updated: 2024/03/27 22:23:15 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3D_utils.h"
# include "libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define SCREEN_W	600
# define SCREEN_H	600
# define MAP_POS	50

# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define CYAN	0x0000FFFF

/**
 * @brief Return a static instance of the game struct.
 *
 * @return t_game *
 */
t_game	*game(void);

// =============================================================================
//                               INIT_EXIT
// =============================================================================
//
//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ INIT.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief Initialize the game structure. gets mlx instance, window pointer,
 * screen buffer.
 */
void	init_game(void);

//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ EXIT.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief destroy the game structure. destroy window pointer and screen buffer
 */
void		exit_game(int exit_status);
void		free_array(char **arr);



// =============================================================================
// RENDER
// =============================================================================
// SHAPES.C ============================================
/**
 * @brief Write a single pixel to the img buffer at position [x,y].
 *
 * @param img
 * @param x
 * @param y
 * @param color
 */
void		render_pixel(t_img *img, int x, int y, int color);

/**
 * @brief prints the error message and exit the game returning the exit_status
 *
 * @param err_msg
 * @param exit_status
 */
void	exit_error(char *err_msg, char *var);

/**
 * @brief quit the game. The function is hooked to the mlx_loop and called upon
 * closing the window.
 */
int		quit_window(void);

//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ FREE.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief frees the map.
 */
void	free_map(void);

// =============================================================================
//                                 RENDER
// =============================================================================
//
//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ FRAME.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
int		render_frame(void);

//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ BASIC_RENDERING.C \_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief Combines the RGB color values into a single integer representation.
 *
 * This function takes the individual color values (red, green,
 * blue) as arguments and combines them into a single integer representation.
 * The color values should be in the range of 0 to 255 (1 byte).
 *
 * @param r The red color value.
 * @param g The green color value.
 * @param b The blue color value.
 * @return An integer representation of the combined RGB color values.
 */
int		create_trgb(int t, int r, int g, int b);

/**
 * @brief Write a single pixel to the img buffer at position [x,y].
 *
 * @param img
 * @param x
 * @param y
 * @param color
 */
void	render_pixel(t_img *img, int x, int y, int color);

/**
 * @brief Write a square to the img buffer. the [x,y] position of the square
 * correspond to its upper left corner.
 *
 * @param img
 * @param square
 */
void	render_square(t_img *img, t_square square);

//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ MINIMAP.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief renders minimap on the screen buffer.
 */
void	render_minimap(void);

// =============================================================================
// EVENTS
// =============================================================================
//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ EVENTS.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
int		key_listener(int keycode);

// =============================================================================
// UTILS
// =============================================================================
// == UTILS.C ============================================
bool		is_player(char c);
bool		is_floor(char c);
bool		is_wall(char c);
bool		ft_is_digit(char *str);




// =============================================================================
// PARSER
// =============================================================================
// == MAP_CHECK.C ============================================
int			check_file(char *str, char *ext);
void		parse_file(char	*file);


#endif

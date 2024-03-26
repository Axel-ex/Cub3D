/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:51:53 by Axel              #+#    #+#             */
/*   Updated: 2024/03/26 17:52:01 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include "cub3D_utils.h"
# include "libft.h"
# include "mlx.h"

/**
 * @brief Return a static instance of the game struct.
 *
 * @return t_game *
 */
t_game		*game(void);


// =============================================================================
// INIT_EXIT
// =============================================================================
// INIT.C ============================================
/**
 * @brief Initialize the game structure. gets mlx instance, window pointer,
 * screen buffer.
 */
int		init_game(void);

// EXIT.C ============================================
/**
 * @brief destroy the game structure. destroy window pointer and screen buffer
 */
void		exit_game(void);

/**
 * @brief quit the game. The function is hooked to the mlx_loop and called upon
 * closing the window.
 */
int			quit_window(void);

// =============================================================================
// RENDER
// =============================================================================
int			render_frame();

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
 * @brief Write a square to the img buffer. the [x,y] position of the square
 * correspond to its upper left corner.
 *
 * @param img
 * @param square
 */
void		render_square(t_img *img, t_square square);

// COLORS.C ============================================
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
int			create_trgb(int t, int r, int g, int b);

// MINIMAP.C ============================================
/**
 * @brief renders minimap on the screen buffer.
 */
void		render_minimap(void);

// =============================================================================
// EVENTS
// =============================================================================
// EVENTS.C ============================================
int			key_listener(int keycode);

// =============================================================================
// UTILS
// =============================================================================
// UTILS.C ============================================
bool		is_player(char c);
bool		is_floor(char c);
bool		is_wall(char c);
void		print_map(void);

#endif

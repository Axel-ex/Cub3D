/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:51:53 by Axel              #+#    #+#             */
/*   Updated: 2024/04/11 11:30:16 by Axel             ###   ########.fr       */
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
# include <math.h>

/**
 * @brief Return a static instance of the game struct.
 *
 * @return t_game *
 */
t_game	*game(void);

// =============================================================================
//                               INIT_EXIT
// =============================================================================
// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ INIT.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief Initialize the game structure. allocate memory for the data contained 
 * in the file to parse.
 */

void	init_game(void);

/**
 * @brief init mlx instance and window, set the hook and start the loop
 */
void	start_game(void);

// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ INIT_PLAYER.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
void	init_player(void);

// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ EXIT.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief destroy the game structure. destroy window pointer and screen buffer
 */
void		exit_game(int exit_status);

/**
 * @brief prints the error message and the variable passed as arguments.
 *
 * @param err_msg
 * @param var
 */
void	exit_error(char *err_msg, char *var);

/**
 * @brief quit the game. The function is hooked to the mlx_loop and called upon
 * closing the window.
 */
int		quit_window(void);

// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ FREE.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief frees the map.
 */
void	free_map_info(void);
void	free_textures(void);

// =============================================================================
//                                 RENDER
// =============================================================================
// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ FRAME.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief renders on the screen buffer and send it to screen. Minimap, player
 * and 3D scene will be rendered on screen.
 *
 * @return 
 */
int		render_frame(void);

int		shader(double wall_dist, int color);

void	render_v_line(t_ray *ray, int x);
int	shader_ceiling(int dist, int color);
int	shader_floor(int dist, int color);

// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ BASIC_RENDERING.C \_/=\_/=\_/=\_/=\_/=\_
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
void	render_pixel(t_pos	pos, int color);

/**
 * @brief Write a square to the img buffer. the [x,y] position of the square
 * correspond to its upper left corner.
 *
 * @param img
 * @param square
 */
void	render_square(t_square square);

/**
 * @brief Write a line to the img buffer.
 *
 * @param start 
 * @param dir 
 * @param length 
 * @param color 
 */
void	render_line(t_pos start, t_pos dir, int length, int color);
// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ MINIMAP.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief renders minimap on the screen buffer.
 */
void	render_minimap(void);

// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ TEXTURES.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
void	update_texture_pixel(t_ray *ray, int curr_x);


// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ RAYCASTING.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
void	raycaster(void);

// =============================================================================
//                                  EVENTS
// =============================================================================
//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ EVENTS.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
int		key_listener(int keycode);
int		key_press(int keycode);
int 	key_release(int keycode);
int		validate_move(double new_x, double new_y);
int		move_player();
int	rotate_camera(t_rotation direction);




// =============================================================================
//                                   UTILS
// =============================================================================
//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ MAP_UTILS.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
bool		is_player(char c);
bool		is_floor(char c);
bool		is_wall(char c);
bool		ft_is_digit(char *str);
bool		is_map_row(char *line);
char		*ft_strstr(char *str, char *to_find);
bool		ft_isspace(char c);
char		*trim_elements(char *str, char **chars);
char 		*cleaner(char *str);
void		order_check(char *str);



//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ MATRIX_UTILS.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
size_t		get_matrix_len(char **matrix);
void		free_matrix(char **matrix);
void		matrix_append(char ***matrix_ptr, char *to_append);

//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ DEBUG.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief prints the map highlighting in red the position passed as arg.
 *
 * @param err_pos position at which error occured.
 */
void	print_map(t_pos err_pos);

/**
 * @brief print player direction, position on the map and on the screen.
 */
void	print_player_pos(void);

//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ POSITION_UTILS.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief converts the pos on the map to real pos on screen.
 *
 * @param pos 
 * @return 
 */
t_pos	to_screen_pos(t_pos pos);

/**
 * @brief converts the pos on screen to the corresponding one in the map.
 *
 * @param pos	position to convert.
 * @return		converted position.
 */
t_pos	to_map_pos(t_pos pos);

/**
 * @brief reverse a direction vector / returns opposite of a point.
 *
 * @param dir 
 * @return 
 */
t_pos	reverse_dir(t_pos dir);

/**
 * @brief add two positions and return the result.
 *
 * @param p1
 * @param p2
 * @return
 */
t_pos	add_pos(t_pos p1, t_pos p2);


/**
 * @brief Centers a given position on the screen by offsetting it.This function
 * aims to adjust the position to ensure that the center of an object aligns with
 * the specified position.
 *
 * @param pos  The original position to be centered.
 * @param size The size of the object to be centered, used to compute the offset.
 * @return     The centered position.
 */

t_pos center_position(t_pos pos, int size);


// =============================================================================
//                                  PARSER
// =============================================================================
//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ PARSE_FILE.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
void		check_file(char *str, char *ext, char *alt);
void		parse_file(char	*file);


//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ CHECK_MAP.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief performs check on maps. check if the map is closed by walls, if it has
 * invalid chars, and it has empty lines.
 *
 * @param map 
 */
void		check_map(char	**map);

// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ LOAD_MAP.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
void	load_textures(void);

#endif

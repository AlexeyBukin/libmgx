/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_full.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 22:19:08 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/12 22:36:10 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** wider 'mlx.h' header
** gives you a chance to use structures from 'mxl_int.h'
** you do not have to include both mlx.h and 'mlx_full.h'
** normified
*/

#ifndef MLX_FULL_H
# define MLX_FULL_H

# ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
# else
#  ifdef _WIN32
#   include <windows.h>
#  endif
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
# endif

# include "mlx_int.h"

# define MLX_KEY_G 5

#define MLX_HOOK_KEY_PRESS     2
#define MLX_HOOK_KEY_RELEASE   3
#define MLX_HOOK_MOUSE_PRESS   4
#define MLX_HOOK_MOUSE_RELEASE 5
#define MLX_HOOK_MOUSE_MOVE    6
#define MLX_HOOK_CLOSE         17
#define MLX_HOOK_EXPOSE        12

void			*mlx_init();
/*
**  needed before everything else.
**  return (void *)0 if failed
*/

/*
** Basic actions
*/

void			*mlx_new_window(void *mlx_ptr, int size_x, int size_y,
					char *title);

/*
**  return void *0 if failed
*/

int				mlx_clear_window(void *mlx_ptr, void *win_ptr);
int				mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x,
					int y, int color);
/*
**  origin for x & y is top left corner of the window
**  y down is positive
**  color is 0x00RRGGBB
*/

/*
** Image stuff
*/

void			*mlx_new_image(void *mlx_ptr, int width,
					int height);
/*
**  return void *0 if failed
*/
char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
					int *size_line, int *endian);
/*
**  endian	: 0 = sever X is little endian, 1 = big endian
**  endian	: useless on macos,
**				client and graphical framework have the same endian
*/

int				mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
					void *img_ptr, int x, int y);
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);

/*
** dealing with Events
*/

int				mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_expose_hook (void *win_ptr, int (*fun_ptr)(), void *param);

int				mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int				mlx_loop (void *mlx_ptr);

/*
**	hook funct are called as follow :
**		expose_hook(void *param);
**		key_hook(int keycode, void *param);
**		mouse_hook(int button, int x,int y, void *param);
**		loop_hook(void *param);
*/

/*
**  Usually asked...
*/

int				mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y,
					int color, char *string);

void			*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
					int *width, int *height);
int				mlx_destroy_window(void *mlx_ptr, void *win_ptr);

/*
**  generic hook system for all events, and minilibX functions that
**    can be hooked. Some macro and defines from X11/X.h are needed here.
*/

int				mlx_hook(void *win_ptr, int x_event, int x_mask,
				int (*funct)(), void *param);

int				mlx_do_key_autorepeatoff(void *mlx_ptr);
int				mlx_do_key_autorepeaton(void *mlx_ptr);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 04:58:14 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 10:26:43 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGX_H
# define MGX_H

//# include<time.h>
# include "libft.h"
# include "mgx_base_s.h"
# include "mgx_libs.h"
# include "mgx_input.h"
# include "mgx_struct.h"
# include "mgx_free.h"
# include "mgx_mlx.h"

# define PIXEL_WHITE (t_pixel){255, 255, 255, 0}

int				mgx_init(char *appname, t_size2 size, t_mgx **mgx_ptr);
t_mgx_win		*mgx_win_init(t_mgx *mgx, t_mgx_lib_type libtype, t_size2 size, char *title);
int				mgx_win_buf_add(t_mgx_win *win);
int				mgx_loop(t_mgx *mgx, int (*loop_func)(), void *loop_data);

int				mgx_mouse_clicked_left(t_mgx_win *win);
int				mgx_mouse_pressed_left(t_mgx_win *win);
int				mgx_mouse_released_left(t_mgx_win *win);
int				mgx_mouse_clicked_right(t_mgx_win *win);
//int				mgx_mouse_pressed_right(t_mgx_win *win);
//int				mgx_mouse_released_right(t_mgx_win *win);
int				mgx_pixel_put(t_pixel_buf *buf, t_size2 coords, t_pixel pixel);

int				mgx_win_draw(t_mgx_win *win);
t_pixel_buf		*mgx_get_win_buf(t_mgx_win *win, int id);

int				mgx_buf_clear(t_pixel_buf *pix_buf);
int				mgx_buf_merge(t_pixel_buf *dest, t_pixel_buf *src);
t_pixel_buf		*mgx_buf_init(t_mgx_win *win);

int				mgx_draw_line(t_pixel_buf *pix_buf, t_rect line);

#endif

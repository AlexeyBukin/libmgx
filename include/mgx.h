/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 04:58:14 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 08:27:56 by kcharla          ###   ########.fr       */
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

int				mgx_init(char *appname, t_size2 size, t_mgx **mgx_ptr);
t_mgx_win		*mgx_win_init(t_mgx *mgx, t_mgx_lib_type libtype, t_size2 size, char *title);
t_pixel_buf		*mgx_buf_init(t_mgx_win *win);
int				mgx_win_buf_add(t_mgx_win *win);
int				mgx_loop(t_mgx *mgx, int (*loop_func)(), void *loop_data);

int				mgx_mouse_clicked_left(t_mgx_win *win);
int				mgx_mouse_pressed_left(t_mgx_win *win);

int				mgx_pixel_put(t_pixel_buf *buf, t_size2 coords, t_pixel pixel);
int				mgx_win_draw(t_mgx_win *win);

#endif

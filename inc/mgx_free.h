/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_free.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:56:17 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/15 19:19:10 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGX_FREE_H
# define MGX_FREE_H

# include "mgx_base_s.h"
# include "mgx_struct.h"

int			mgx_free(t_mgx *mgx);
int			mgx_free_pixel_buf(t_pixel_buf *buf);
int			mgx_free_pixel_buf_list(t_pixel_buf *buf);
int			mgx_free_win(t_mgx_win *win);
int			mgx_free_win_list(t_mgx_win *win);

#endif
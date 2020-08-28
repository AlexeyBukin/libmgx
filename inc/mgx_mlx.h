/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 07:11:19 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 08:05:43 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGX_MLX_H
# define MGX_MLX_H

# include "mlx_full.h"
# include "mgx_base_s.h"
# include "mgx_struct.h"
# include "mgx_input.h"

int			mgx_mlx_close_press(void *input_ptr);
int			mgx_mlx_mouse_press(int bn_mlx, int x, int y, void *input_ptr);
int			mgx_mlx_mouse_release(int bn_mlx, int x, int y, void *input_ptr);
int			mgx_mlx_mouse_move(int x, int y, void *input_ptr);
int			mgx_mouse_set_mlx_button(t_m_buttons *bs, int bn, int val);

#endif
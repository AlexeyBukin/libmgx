/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 07:11:19 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 09:58:32 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGX_INPUT_H
# define MGX_INPUT_H

#include "libft.h"

typedef enum		s_mgx_mlx_mouse
{
	MLX_MOUSE_LB = 1,
	MLX_MOUSE_RB,
	MLX_MOUSE_MB,
	MLX_MOUSE_SC_UP,
	MLX_MOUSE_SC_DOWN,
	MLX_MOUSE_SC_LEFT,
	MLX_MOUSE_SC_RIGHT
}					t_mgx_mlx_mouse;

typedef struct		s_m_buttons
{
	int				left;
	int				right;
	int				middle;
	int				w_up;
	int				w_down;
	int				w_left;
	int				w_right;
}					t_m_buttons;

typedef struct		s_mouse
{
	t_int2			pos;
	t_int2			pos_old;
	t_int2			move;
	t_m_buttons		buttons;
	t_m_buttons		buttons_old;
}					t_mouse;

typedef struct		s_mgx_input
{
	t_mouse			mouse;
	t_bool			close;
}					t_mgx_input;

#endif
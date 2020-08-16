/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_lib_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 07:54:27 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 08:03:57 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgx.h"

int			mgx_mlx_mouse_release(int button_mlx, int x, int y, void *input_ptr)
{
	t_mgx_input		*input;

	if ((input = (t_mgx_input*)input_ptr) == NULL)
		return (-1);
	input->mouse.x = x;
	input->mouse.y = y;
	if (mgx_mouse_set_mlx_button(&(input->mouse.buttons), button_mlx, FALSE))
		return (-1);
	return (0);
}

int			mgx_mlx_mouse_move(int x, int y, void *input_ptr)
{
	t_mgx_input		*input;

	if ((input = (t_mgx_input*)input_ptr) == NULL)
		return (-1);
	input->mouse.x = x;
	input->mouse.y = y;
	return (0);
}

int			mgx_mlx_mouse_press(int button_mlx, int x, int y, void *input_ptr)
{
	t_mgx_input		*input;

	if ((input = (t_mgx_input*)input_ptr) == NULL)
		return (-1);
	input->mouse.x = x;
	input->mouse.y = y;
	if (mgx_mouse_set_mlx_button(&(input->mouse.buttons), button_mlx, TRUE))
		return (-1);
	return (0);
}

int			mgx_mlx_close_press(void *input_ptr)
{
	t_mgx_input		*input;

	if ((input = (t_mgx_input*)input_ptr) == NULL)
		return (-1);
	input->close = 1;
	return (0);
}

int			mgx_mouse_set_mlx_button(t_m_buttons *buttons, int button_mlx, int val)
{
	if (buttons == NULL)
		return (-1);
	if (button_mlx == MLX_MOUSE_LB)
		buttons->left = val;
	else if (button_mlx == MLX_MOUSE_RB)
		buttons->right = val;
	else if (button_mlx == MLX_MOUSE_MB)
		buttons->middle = val;
	else if (button_mlx == MLX_MOUSE_SC_UP)
		buttons->w_up = val;
	else if (button_mlx == MLX_MOUSE_SC_DOWN)
		buttons->w_down = val;
	else if (button_mlx == MLX_MOUSE_SC_LEFT)
		buttons->w_left = val;
	else if (button_mlx == MLX_MOUSE_SC_RIGHT)
		buttons->w_right = val;
	else
		return (-1);
	return (0);
}



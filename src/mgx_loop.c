/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 05:41:58 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 10:22:44 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgx.h"

/*
** Initialization
*/

int				mgx_input_mouse_move_update(t_mgx_win *wl)
{
	while (wl != NULL)
	{
		wl->input.mouse.move.x = wl->input.mouse.pos.x - wl->input.mouse.pos_old.x;
		wl->input.mouse.move.y = wl->input.mouse.pos.y - wl->input.mouse.pos_old.y;
		wl = wl->next;
	}
	return (0);
}

int			mgx_input_update(t_mgx_win *win_list)
{
	while (win_list != NULL)
	{
//		win_list->input.mouse.buttons_old = win_list->input.mouse.buttons;
		win_list->input.mouse.buttons_old.left = win_list->input.mouse.buttons.left;
		win_list->input.mouse.buttons_old.right = win_list->input.mouse.buttons.right;
//		win_list->input.mouse.buttons_old = win_list->input.mouse.buttons;
//		win_list->input.mouse.buttons_old = win_list->input.mouse.buttons;
//		win_list->input.mouse.buttons_old = win_list->input.mouse.buttons;
//		win_list->input.mouse.buttons_old = win_list->input.mouse.buttons;
		win_list->input.mouse.pos_old = win_list->input.mouse.pos;// = win_list->input.mouse.y;
		win_list = win_list->next;
	}
//	ft_printf("updated input!\n");
	return (0);
}

int			mgx_loop_func(void *mgx_ptr)
{
	t_mgx		*mgx;

	if ((mgx = (t_mgx*)mgx_ptr) == NULL)
		return (-1);
//	if (mgx_input_mouse_move_update(mgx->win_list))
//		return (-1);
	if (mgx->loop_func != NULL)
		if (mgx->loop_func(mgx->loop_data))
			return (-1);
//	mgx->loop_func(mgx->loop_data);
	if (mgx_input_update(mgx->win_list))
		return (-1);
	return (0);
}

//mgx_mouse_pressed_right

int			mgx_mouse_clicked_right(t_mgx_win *win)
{
	if (win == NULL)
		return (-1);
	return (win->input.mouse.buttons_old.right == FALSE &&
			win->input.mouse.buttons.right == TRUE);
}

int			mgx_mouse_pressed_left(t_mgx_win *win)
{
	if (win == NULL)
		return (-1);
	return (win->input.mouse.buttons_old.left == TRUE &&
			win->input.mouse.buttons.left == TRUE);
}

int			mgx_mouse_released_left(t_mgx_win *win)
{
	if (win == NULL)
		return (-1);
	return (win->input.mouse.buttons_old.left == TRUE &&
			win->input.mouse.buttons.left == FALSE);
}

int			mgx_mouse_clicked_left(t_mgx_win *win)
{
	if (win == NULL)
		return (-1);
//	ft_printf("updating click: old=%i, new=%i\n", (int)win->input.mouse.buttons_old.left, (int)win->input.mouse.buttons.left);
//	if (win->input.mouse.buttons_old.left == (unsigned)0)
//	{
//		if (win->input.mouse.buttons.left == (unsigned)1)
//			return (1);
//	}
//	return (0);

	return (win->input.mouse.buttons_old.left == FALSE &&
			win->input.mouse.buttons.left == TRUE);
}

int			mgx_loop(t_mgx *mgx, int (*loop_func)(), void *loop_data)
{
	if (mgx == NULL)
		return (-1);
	mgx->loop_data = loop_data;
	mgx->loop_func = loop_func;
	mlx_loop_hook(mgx->libs.mlx, mgx_loop_func, mgx);
	mlx_loop(mgx->libs.mlx);
	return (0);
}

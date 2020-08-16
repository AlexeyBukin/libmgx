/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 10:18:44 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 08:21:10 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgx.h"

typedef struct		s_liner
{
	t_mgx			*mgx;
	t_int2			last_click;// = (t_int2){-1, -1};
}					t_liner;

//int		draw_line(t_mgx_win *win, t_rect line)
//{
//	//draw_line
//	return (0);
//}
//

int		liner_loop(void *liner_ptr)
{
	t_liner		*liner;
//	t_int2		pos;
//	t_rect		line;
	t_mgx		*mgx;

	if ((liner = (t_liner*)liner_ptr) == NULL)
		return (-1);
	if ((mgx = liner->mgx)== NULL)
		return (-1);
	if (mgx->win_active == NULL)
		return (-1);
	if (mgx->win_active->input.close)
	{
		ft_printf("pressed X button, exiting...\n");
		exit(0);
	}
	if (mgx_mouse_clicked_left(mgx->win_active))
	{
		liner->last_click.x = mgx->win_active->input.mouse.x;
		liner->last_click.y = mgx->win_active->input.mouse.y;
		mgx_pixel_put(mgx->win_active->bufs,
				(t_size2){liner->last_click.x, liner->last_click.y},
				(t_pixel){255, 255, 255, 255});
		ft_printf("just clicked left!\n");
		mgx_win_draw(mgx->win_active);
	}
//	else if (mgx_mouse_pressed_left(mgx->win_active))
//	{
//		win_buf_clear(get_win_buf(mgx->win_active, 2));
//	}
//	ft_printf("exiting...\n");
//	exit(0);
//	// not required as we do not dereference 'win' pointer directly
//	if ((win = mgx->win_active) == NULL)
//		return (-1);
//	if (just_clicked_left(mgx->win_active))
//	{
//		(t_liner*)liner->last_click = get_mouse_coords(mgx->win_active);
//	}
//	else if (is_pressed_left(mgx->win_active))
//	{
//		win_buf_clear(get_win_buf(mgx->win_active, 2));
//		pos = (t_liner*)liner->last_click;
//		line.x1 = pos.x;
//		line.y1 = pos.y;
//		pos = get_mouse_coords(mgx->win_active);
//		line.x2 = pos.x;
//		line.y2 = pos.y;
//		draw_line(get_win_buf(mgx->win_active, 2), line);
//	}
//	else if (is_pressed_left(mgx->win_active))
//	{
//		win_buf_transfer(get_win_buf(mgx->win_active, 1), get_win_buf(mgx->win_active, 2))
////		same as
////		win_buf_transfer(mgx->win_active->bufs, get_win_buf(mgx->win_active, 2))
//		(t_liner*)liner->last_click = (t_int2){-1, -1};
//	}
	return (0);
}

int				main()
{
	t_liner		liner;

	ft_bzero(&liner, sizeof(t_liner));
	if (mgx_init("liner.app", (t_size2){640, 480}, &(liner.mgx)))
		return (-1);
	if (mgx_win_buf_add(liner.mgx->win_active))
		return (-1);
	if (mgx_loop(liner.mgx, liner_loop, &liner))
		return (-1);
	return (0);
}
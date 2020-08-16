/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_win_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 23:29:21 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 08:03:57 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgx.h"

int				mgx_win_mlx_init(t_mgx_win *win)
{
	if (win == NULL)
		return (-1);
	if (win->mgx == NULL)
		return (-1);

	win->lib.mlx.mlx = win->mgx->libs.mlx;
	win->lib.mlx.win = mlx_new_window(win->lib.mlx.mlx, win->size.x, win->size.y, win->title);

	mlx_hook(win->lib.mlx.win, MLX_HOOK_MOUSE_PRESS, 0, mgx_mlx_mouse_press, (void*)&(win->input));
	mlx_hook(win->lib.mlx.win, MLX_HOOK_MOUSE_RELEASE, 0, mgx_mlx_mouse_release, (void*)&(win->input));
	mlx_hook(win->lib.mlx.win, MLX_HOOK_MOUSE_MOVE, 0, mgx_mlx_mouse_move, (void*)&(win->input));
	mlx_hook(win->lib.mlx.win, MLX_HOOK_CLOSE, 0, mgx_mlx_close_press, (void*)&(win->input));

	return (0);
}

t_mgx_win		*mgx_win_init(t_mgx *mgx, t_mgx_lib_type libtype, t_size2 size, char *win_name)
{
	t_mgx_win		*win;

	if (size.x == 0 || size.y == 0 || mgx == NULL)
		return (NULL);
	if (win_name == NULL)
		return (NULL);
	if ((win = (t_mgx_win*)ft_memalloc(sizeof(t_mgx_win))) == NULL)
		return (NULL);
	win->size = size;
	win->title = ft_strdup(win_name);
	win->type = libtype;
	win->mgx = mgx;

	if (libtype == LIB_MLX)
		if (mgx_win_mlx_init(win))
			return (NULL);
//	if ((win->lib = mgx_lib_win_init(win)) == NULL)
//		return (NULL);
//	;

//	if (mgx_win_add_buf(mgx->win_active))
//		return (NULL);

	if (mgx_win_buf_add(win))
	{
//		mgx_win_free(win);
		return (NULL);
	}
//	if ((win->bufs = mgx_buf_init(win)) == NULL)
//	{
////		mgx_win_free(win);
//		return (NULL);
//	}

	return (win);
}

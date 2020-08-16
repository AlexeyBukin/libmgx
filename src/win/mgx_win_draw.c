/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_win_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 23:58:56 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 09:41:43 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgx.h"

int			mgx_win_draw(t_mgx_win *win)
{
	if (win == NULL)
		return (-1);
	if (win->type == LIB_MLX)
	{
		if (win->bufs == NULL)
			return (-1);
		mlx_clear_window(win->lib.mlx.mlx, win->lib.mlx.win);
		mlx_put_image_to_window(win->lib.mlx.mlx, win->lib.mlx.win, win->bufs->lib_ptr, 0, 0);
	}
	else
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:40:22 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/15 20:57:09 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgx.h"

int			mgx_free(t_mgx *mgx)
{
	if (mgx == NULL)
		return (0);
	ft_free(mgx->app_name);
	mgx_free_win_list(mgx->win_list);
	return (0);
}

int			mgx_free_pixel_buf(t_pixel_buf *pixbuf)
{
	if (pixbuf == NULL)
		return (0);
	ft_free(pixbuf->buf);
	ft_free(pixbuf);
	return (0);
}

int			mgx_free_pixel_buf_list(t_pixel_buf *curr)
{
	t_pixel_buf		*next;

	while (curr != NULL)
	{
		next = curr->next;
		mgx_free_pixel_buf(curr);
	}
	return (0);
}

//int			mgx_free_lib_win(t_mgx_lib_win *win, t_mgx_lib_type type)
//{
//	if (win == NULL)
//		return (0);
//	(void)type;
//	return (0);
//}

/*
** TODO free lib_win inside win struct
*/

int			mgx_free_win(t_mgx_win *win)
{
	if (win == NULL)
		return (0);
	ft_free(win->title);
	mgx_free_pixel_buf_list(win->bufs);
	ft_free(win);
	return (0);
}

int			mgx_free_win_list(t_mgx_win *curr)
{
	t_mgx_win	*next;

	while (curr != NULL)
	{
		next = curr->next;
		mgx_free_win(curr);
	}
	return (0);
}
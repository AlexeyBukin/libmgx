/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_win_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 23:58:56 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 00:11:23 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgx.h"

t_pixel_buf		*mgx_win_get_buf_last(t_mgx_win *win)
{
	t_pixel_buf		*last;

	if (win == NULL)
		return (NULL);
	if (win->bufs == NULL)
		return (NULL);
	last = win->bufs;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

int				mgx_win_buf_add(t_mgx_win *win)
{
	t_pixel_buf		*pix_buf;
	t_pixel_buf		*last;

	if (win == NULL)
		return (-1);
	if ((pix_buf = mgx_buf_init(win)) == NULL)
		return (-1);
	if (win->bufs == NULL)
	{
		win->bufs = pix_buf;
		return (0);
	}
	if ((last = mgx_win_get_buf_last(win)) == NULL)
		return (-1);
	last->next = pix_buf;
	return (0);
}

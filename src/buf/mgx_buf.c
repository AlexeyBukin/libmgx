/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_buf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 00:01:58 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 08:17:32 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgx.h"

//t_pixel_buf		*mgx_buf_init(t_size2 size)
//{
//	t_pixel_buf		*buf;
//
//	if ((buf = (t_pixel_buf*)ft_memalloc(sizeof(t_pixel_buf))) == NULL)
//		return (NULL);
//	//TODO give ids to buffers
//	buf->id = 0;
//	buf->size = size;
//	buf->next = NULL;
//	if ((buf->buf = (t_pixel*)ft_memalloc(
//			sizeof(t_pixel) * buf->size.x * buf->size.y)) == NULL)
//	{
//		ft_free(buf);
//		return (NULL);
//	}
//	return (buf);
//}

int				mgx_pixel_put(t_pixel_buf *buf, t_size2 coords, t_pixel pixel)
{
	if (buf == NULL)
		return (-1);
	if (buf->buf == NULL)
		return (-1);
	if (buf->size.x <= coords.x || buf->size.y <= coords.y)
		return (-1);
	(buf->buf)[coords.y * buf->size.x + coords.x] = pixel;
	return (0);
}

t_pixel_buf		*mgx_buf_init(t_mgx_win *win)
{
	t_pixel_buf		*buf;

	if (win == NULL)
		return (NULL);
	if ((buf = (t_pixel_buf*)ft_memalloc(sizeof(t_pixel_buf))) == NULL)
		return (NULL);
	//TODO give ids to buffers
	buf->id = 0;
	buf->size = win->size;
	buf->next = NULL;
	if ((buf->buf = (t_pixel*)ft_memalloc(
			sizeof(t_pixel) * buf->size.x * buf->size.y)) == NULL)
		return (NULL);
	return (buf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_buf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 00:01:58 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 10:57:49 by kcharla          ###   ########.fr       */
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

int				mgx_pixel_put(t_pixel_buf *buf, t_int2 coords, t_pixel pixel)
{
	if (buf == NULL)
		return (-1);
	if (buf->buf == NULL)
		return (-1);
	if (coords.x < 0 || coords.y < 0 || coords.x >= (int)buf->size.x || coords.y >= (int)buf->size.y)
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
	buf->size = win->size;
	buf->next = NULL;
	if (win->type == LIB_MLX)
	{
		buf->lib_ptr = mlx_new_image(win->lib.mlx.mlx, win->size.x, win->size.y);
		int		i_dont_give_a_f = 0;
		buf->buf = (t_pixel*)mlx_get_data_addr(buf->lib_ptr,
					&i_dont_give_a_f, &i_dont_give_a_f, &i_dont_give_a_f);
	}
	else
	{
		//TODO give ids to buffers
		if ((buf->buf = (t_pixel*)ft_memalloc(
				sizeof(t_pixel) * buf->size.x * buf->size.y)) == NULL)
			return (NULL);
	}

	return (buf);
}

int				mgx_buf_merge(t_pixel_buf *dest, t_pixel_buf *src)
{
	size_t		i;

	if (dest == NULL || src == NULL)
		return (-1);
	if (dest->buf == NULL || src->buf == NULL)
		return (-1);
	if (dest->size.x != src->size.x || dest->size.y != src->size.y)
		return (-1);
	i = 0;
	while (i < dest->size.x * dest->size.y)
	{
		dest->buf[i].r = dest->buf[i].r | src->buf[i].r;
		dest->buf[i].g = dest->buf[i].g | src->buf[i].g;
		dest->buf[i].b = dest->buf[i].b | src->buf[i].b;
		dest->buf[i].a = dest->buf[i].a | src->buf[i].a;
		i++;
	}
	return (0);
}

//int				mgx_draw_line(t_pixel_buf *pix_buf, t_rect line)
//{
//	//TODO redpo to normal version
////	PIXEL_WHITE
//	if (line.x1 < 0 || line.x2 < 0 || line.y1 < 0 || line.y2 < 0)
//		return (-1);
//	mgx_pixel_put(pix_buf, (t_size2){line.x1, line.y1}, PIXEL_WHITE);
//	mgx_pixel_put(pix_buf, (t_size2){line.x2, line.y2}, PIXEL_WHITE);
//	return (0);
//}

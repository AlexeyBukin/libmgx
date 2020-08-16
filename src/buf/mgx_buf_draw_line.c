/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_buf_draw_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 10:42:11 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 11:05:34 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgx.h"

/*
** Function that draws one simple line by x axis
*/

static void	draw_simple_line_x(t_pixel_buf *data, t_int2 p1, t_int2 p2)
{
	int				p2z;
	int				p1z;
	int				ddz;
	int				dcol;
	t_int2			d;

	if (p1.x > p2.x)
		return (draw_simple_line_x(data, p2, p1));
	ddz = 0;
	p2z = ft_abs(p2.x - p1.x);
	dcol = p2.y - p1.y;
	p1z = ft_abs(dcol);
	dcol = (dcol > 0) - (dcol < 0);
	d.x = p1.x;
	d.y = p1.y;
	while (d.x <= p2.x)
	{
		mgx_pixel_put(data, d, PIXEL_WHITE);
		ddz += p1z;
		if (2 * ddz >= p2z)
		{
			d.y += dcol;
			ddz -= p2z;
		}
		d.x++;
	}
}

/*
** Function that draws one simple line by y axis
*/

static void	draw_simple_line_y(t_pixel_buf *data, t_int2 p1, t_int2 p2)
{
	int				p2z;
	int				p1z;
	int				ddz;
	int				dcol;
	t_int2			d;

	if (p1.y > p2.y)
		return (draw_simple_line_y(data, p2, p1));
	ddz = 0;
	p2z = ft_abs(p2.y - p1.y);
	dcol = p2.x - p1.x;
	p1z = ft_abs(dcol);
	dcol = (dcol > 0) - (dcol < 0);
	d.x = p1.x;
	d.y = p1.y;
	while (d.y <= p2.y)
	{
		mgx_pixel_put(data, d, PIXEL_WHITE);
		ddz += p1z;
		if (2 * ddz >= p2z)
		{
			d.x += dcol;
			ddz -= p2z;
		}
		d.y++;
	}
}

/*
** Function that draws one simple line
*/

int			mgx_draw_line(t_pixel_buf *data, t_rect l)
{
	double k;

	if (data == NULL)
		return (-1);
	if ((l.p1.x) == (l.p2.x) && (l.p1.y) == (l.p2.y))
	{
		mgx_pixel_put(data, l.p1, PIXEL_WHITE);
		return (0);
	}
	k = ((l.p2.x) == (l.p1.x)) ? 1 : ((l.p2.y) - (l.p1.y) + 0.0)
							/ ((l.p2.x) - (l.p1.x) + 0.0);
	if (ft_abs(k) >= 1)
		draw_simple_line_y(data, l.p1, l.p2);
	else
		draw_simple_line_x(data, l.p1, l.p2);
	return (0);
}

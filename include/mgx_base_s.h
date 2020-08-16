/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 04:58:14 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/13 07:41:01 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGX_BASE_H
# define MGX_BASE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_pixel
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_pixel;

typedef struct		s_size2
{
	size_t			x;
	size_t			y;
}					t_size2;

typedef struct		s_pixel_buf
{
	t_pixel				*buf;
	t_size2				size;
	unsigned			id;
	struct s_pixel_buf	*next;
}					t_pixel_buf;

typedef struct		s_int2
{
	int				x;
	int				y;
}					t_int2;

typedef struct		s_rect
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_rect;

#endif
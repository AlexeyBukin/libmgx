/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:17:30 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 08:03:08 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGX_STRUCT_H
# define MGX_STRUCT_H

//# include<time.h>
# include "mgx_base_s.h"
# include "mgx_mlx_s.h"


typedef enum		e_mgx_lib_type
{
	LIB_ALL = -1,
	LIB_MLX,
	LIB_NUM
}					t_mgx_lib_type;

typedef union		u_mgx_lib_win
{
	t_mgx_mlx		mlx;
	//				sdl;
	//				vulkan;
	//				gl;
	//				csfm;
	//				glfw;
}					t_mgx_lib_win;

//mlx_win_list_t
typedef struct		s_mgx_win
{
	t_pixel_buf			*bufs;
	t_size2				size;
	char				*title;
	t_mgx_input			input;
	t_mgx_lib_type		type;
	t_mgx_lib_win		lib;
	struct s_mgx_win	*next;
	struct s_mgx		*mgx;
}					t_mgx_win;

typedef struct		s_mgx_libs
{
	mlx_ptr_t		*mlx;
	//				sdl;
	//				vulkan;
	//				gl;
	//				csfm;
	//				glfw;
}					t_mgx_libs;

typedef struct		s_mgx
{
	char			*app_name;
	t_mgx_win		*win_active;
	t_mgx_win		*win_list;
	void			*loop_data;
	int				(*loop_func)();
	t_mgx_libs		libs;
//	void			loop_func;
//	long long		timer;
}					t_mgx;

#endif
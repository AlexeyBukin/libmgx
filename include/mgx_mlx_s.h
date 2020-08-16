/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 07:11:19 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 08:02:39 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGX_MLX_S_H
# define MGX_MLX_S_H

# include "mlx_full.h"
# include "mgx_base_s.h"
# include "mgx_struct.h"
# include "mgx_input.h"

typedef struct		s_mgx_mlx
{
	mlx_ptr_t		*mlx;
	mlx_win_list_t	*win;
}					t_mgx_mlx;

#endif
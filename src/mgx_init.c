/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 05:41:58 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/16 05:32:28 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgx.h"

/*
** Initialization
*/

int			mgx_init(char *appname, t_size2 size, t_mgx **mgx_ptr)
{
	t_mgx			*mgx;

	if (appname == NULL || mgx_ptr == NULL)
		return (-1);
	if (!size.x && !size.y)
		return (-1);
	if ((mgx = (t_mgx*)ft_memalloc(sizeof(t_mgx))) == NULL)
		return (-1);
	mgx->app_name = ft_strdup(appname);
	if ((mgx->libs.mlx = mlx_init()) == NULL)
		return (-1 + mgx_free(mgx));
	if (mlx_do_key_autorepeatoff(mgx->libs.mlx))
		return (-1);
	if ((mgx->win_list = mgx_win_init(mgx, LIB_MLX, size, appname)) == NULL)
		return (-1 + mgx_free(mgx));
	mgx->win_active = mgx->win_list;
	mgx->loop_data = NULL;
	mgx->loop_func = NULL;
	*mgx_ptr = mgx;
	return (0);
}

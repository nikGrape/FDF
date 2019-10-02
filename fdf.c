/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:13:25 by vinograd          #+#    #+#             */
/*   Updated: 2019/10/01 21:10:24 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_dot *param)
{
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->window_x = 2000;
	param->window_y = 1000;
	param->shift_x = param->window_x / 3;
	param->shift_y = param->window_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->window_x, param->window_y, "FDF");
}

int		main(int argc, char **argv)
{
	t_dot	**matrix;

	if (argc != 2)
		ft_error("usage: ./fdf map.fdf");
	matrix = read_map(*++argv);
	set_default(&PRM);
	draw(matrix);
	mlx_key_hook(PRM.win_ptr, deal_key, matrix);
	mlx_loop(PRM.mlx_ptr);
}

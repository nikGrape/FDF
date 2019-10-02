/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:13:25 by vinograd          #+#    #+#             */
/*   Updated: 2019/10/01 18:49:10 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_dot *param)
{
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->shift_x = WINDOW_X / 3;
	param->shift_y = WINDOW_Y / 3;
}

int		main(int argc, char **argv)
{
	t_dot	**matrix;

	matrix = read_map(*++argv);
	set_default(&PRM);
	PRM.mlx_ptr = mlx_init();
	PRM.win_ptr = mlx_new_window(PRM.mlx_ptr, WINDOW_X, WINDOW_Y, "FDF");
	print_menu(PRM);
	draw(matrix);
	mlx_key_hook(PRM.win_ptr, deal_key, matrix);
	mlx_loop(PRM.mlx_ptr);
}

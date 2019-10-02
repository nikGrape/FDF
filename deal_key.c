/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 00:55:04 by Nik               #+#    #+#             */
/*   Updated: 2019/10/01 21:19:05 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 ||\
	key == 91 || key == 28 || key == 84 || key == 19 ||\
	key == '~' || key == '}' || key == '{' || key == '|' ||\
	key == 87 || key == 23 || key == 86 || key == 21 ||\
	key == 49 || key == 88 || key == 22);
}

void	do_key(int key, t_dot **matrix)
{
	if (key == 24 || key == 69)
		PRM.scale += 3;
	if (key == 27 || key == 78)
		PRM.scale -= 3;
	if (key == 91 || key == 28)
		PRM.z_scale += 1;
	if (key == 84 || key == 19)
		PRM.z_scale -= 1;
	if (key == '~')
		PRM.shift_y -= 10;
	if (key == '}')
		PRM.shift_y += 10;
	if (key == '{')
		PRM.shift_x -= 10;
	if (key == '|')
		PRM.shift_x += 10;
	if (key == 49 || key == 87 || key == 23)
		PRM.is_isometric = (PRM.is_isometric) ? 0 : 1;
	if (key == 86 || key == 21)
		PRM.angle += 0.05;
	if (key == 88 || key == 22)
		PRM.angle -= 0.05;
}

void	refresh_window(int key, t_dot **matrix)
{
	if ((key == 0 && PRM.win_y <= 500) || (key == 6 && PRM.win_x <= 500))
		return ;
	if ((key == 1 && PRM.win_y > 2000) || (key == 7 && PRM.win_x > 3000))
		return ;
	if (key == 6)
		PRM.win_x -= 100;
	if (key == 7)
		PRM.win_x += 100;
	if (key == 0)
		PRM.win_y -= 100;
	if (key == 1)
		PRM.win_y += 100;
	mlx_destroy_window(PRM.mlx_ptr, PRM.win_ptr);
	PRM.mlx_ptr = mlx_init();
	PRM.win_ptr = mlx_new_window(PRM.mlx_ptr, PRM.win_x, PRM.win_y, "FDF");
	PRM.shift_x = PRM.win_x / 3;
	PRM.shift_y = PRM.win_y / 3;
	draw(matrix);
	mlx_key_hook(PRM.win_ptr, deal_key, matrix);
	mlx_loop(PRM.mlx_ptr);
}

int		deal_key(int key, t_dot **matrix)
{
	if (is_key(key))
	{
		mlx_clear_window(PRM.mlx_ptr, PRM.win_ptr);
		do_key(key, matrix);
		print_menu(PRM);
		draw(matrix);
	}
	if (key == 6 || key == 7 || key == 0 || key == 1)
		refresh_window(key, matrix);
	if (key == '5')
		exit(0);
	return (0);
}

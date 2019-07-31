/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:13:25 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/28 12:49:33 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, void *param)
{
	ft_putchar(key);
	return (0);
}

void	drow(t_dot a, t_dot b)
{
	float step_x;
	float step_y;
	float max;

	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = MAX(step_x, step_y);
	step_x /= max;
	step_y /= max;
	while ((int)a.x != (int)b.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, 0xBBFAFF);
		a.x += step_x;
		a.y += step_y;
	}
}

int		main(int argc, char **argv)
{
	t_dot	i;
	t_dot	j;
	t_dot	i1;
	t_dot	j1;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 1000, "FDF");
	i.x = 100;
	i.y = 100;
	j.x = 50;
	j.y = 200;
	i1.x = 50;
	i1.y = 100;
	j1.x = 100;
	j1.y = 200;
	// if (argc != 2)
	// 	ft_errors(1);
	drow(i, j);
	drow(i1, j1);
	mlx_key_hook(win_ptr, deal_key, NULL);
	mlx_loop(mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:13:25 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/04 13:45:20 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, void *param)
{
	ft_putchar(key);
	return (0);
}

void	drow(t_dot a, t_dot b, void *mlx_ptr, void *win_ptr)
{
	float step_x;
	float step_y;

	step_x = b.x - a.x;
	step_y = b.y - a.y;
	while (a.x != b.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, step_x, step_y, 0xBBFAFF);
		step_x += 0.5;
		step_y += 1;
	}
}

int		main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;

	if (argc != 2)
		ft_errors(1);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 1000, "FDF");
	float i = 100;
	float j = 120;
	while (i < 250)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xBBFAFF);
		i += 0.125;
		j += 1;
	}
	mlx_key_hook(win_ptr, deal_key, NULL);//keyboard handler
	mlx_loop(mlx_ptr); //to keep program open
}

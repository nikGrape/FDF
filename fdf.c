/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:13:25 by vinograd          #+#    #+#             */
/*   Updated: 2019/09/27 22:25:25 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int		deal_key(int key, void *param)
{
	ft_putchar(key);
	return (0);
}

void	make_scale(t_dot *a, t_dot *b, int scale)
{
	a->x *= scale;
	a->y *= scale;
	a->z *= scale;
	b->x *= scale;
	b->y *= scale;
	b->z *= scale;
}

void	drow(t_dot a, t_dot b, int scale)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	make_scale(&a, &b, scale);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = MAX(step_x, step_y);
	step_x /= max;
	step_y /= max;
	color = (b.z) ? 0xfc031c : 0xBBFAFF;
	while ((int)a.x != (int)b.x || (int)a.y != (int)b.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, a.x + 220, a.y + 220, color);
		a.x += step_x;
		a.y += step_y;
	}
}

int		main(int argc, char **argv)
{
	t_dot	**matrix;
	int		y;
	int		x;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 1000, "FDF");
	matrix = read_map(*++argv);
	
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x].end)
		{
			if (matrix[y+1])
				drow(matrix[y][x], matrix[y+1][x], 40);
			if (matrix[y][x].end)
				drow(matrix[y][x], matrix[y][x+1], 40);

			x++;
		}
		ft_printf("\n");
		y++;
	}
	mlx_key_hook(win_ptr, deal_key, NULL);
	mlx_loop(mlx_ptr);
}

// int main()
// {
// 	t_dot	i;
// 	t_dot	j;

// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, 2000, 1000, "FDF");
// 	i.x = 100;
// 	i.y = 100;
// 	j.x = 100;
// 	j.y = 250;

// 	drow(i, j);
// 	mlx_key_hook(win_ptr, deal_key, NULL);
// 	mlx_loop(mlx_ptr);
// }
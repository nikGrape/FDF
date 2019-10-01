/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 22:11:34 by Nik               #+#    #+#             */
/*   Updated: 2019/10/01 02:45:04 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	fmodule(float i)
{
	return (i < 0) ? -i : i;
}

void	line(t_dot a, t_dot b, t_dot *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = MAX(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	color = (b.z || a.z) ? 0xfc0345 : 0xBBFAFF;
	color = (b.z != a.z) ? 0xfc031c : color;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > WINDOW_X || a.y > WINDOW_Y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw(t_dot **matrix)
{
	int		y;
	int		x;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y+1])
				line(matrix[y][x], matrix[y+1][x], &matrix[0][0]);
			if (!matrix[y][x].is_last)
				line(matrix[y][x], matrix[y][x+1], &matrix[0][0]);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
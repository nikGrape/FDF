/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:13:25 by vinograd          #+#    #+#             */
/*   Updated: 2019/09/30 19:17:40 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/*
** PROJECT:
** We are trying to find where would be the model coordinates in our
** window coordinate system. for that we use coordinate transformations
** (liniar algebra) and also multiply every coordinate to scale.
** If you multiply transofrmation matrix to coordinates of a point you 
** will get new coordinates which describes position of the vector after
** transformation.
**
**  axis Y:	
**	x' = x * cos(a) + z * sin(a)
**	y' = y
**	z' = -x * sin(a) + z * cos(a)
**		
**  axis X;					
**	x' = x;
**	y' = y * cos(a) + z * sin(a)
**	z' = -y * sin(a) + z * cos(a)
**	
**  axis Z;					
**	x' = x * cos(a) - y * sin(a)
**	y' = x * sin(a) + y * cos(a)
**	z' = z 
**
**	To switch center cooditates from [0, 0] to the center of the figure:
**	x = x - map_x / 2  and  y = y - map_y / 2
**
**	To move figure to the center of view:
**	x' = windore_res_width / 2
**	y' = windore_res_high / 2
*/
	// dot->x = dot->x * cos(0.523599) + dot->z * sin(45);
	// dot->y = dot->y * cos(0.523599) + dot->z * sin(45);

void	rotation(t_dot *dot)
{
	dot->x = (dot->x - dot->y) * cos(0.523599);
	dot->y = (dot->x + dot->y) * sin(0.523599) - dot->z;
}

int		deal_key(int key, void *param)
{
	ft_putchar(key);
	return (0);
}

void	make_scale(t_dot *a, t_dot *b, int scale)
{
	a->x *= scale;
	a->y *= scale;
	b->x *= scale;
	b->y *= scale;

	a->z /= 4;
	b->z /= 4;
}

int		modulo(int i)
{
	return (i < 0) ? -i : i;
}

float	fmodulo(float i)
{
	return (i < 0) ? -i : i;
}

void	drow(t_dot a, t_dot b, int scale)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	make_scale(&a, &b, scale);
	rotation(&a);
	rotation(&b);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = MAX(fmodulo(step_x), fmodulo(step_y));
	step_x /= max;
	step_y /= max;
	color = (b.z || a.z) ? 0xfc031c : 0xBBFAFF;

	while (modulo(a.x - b.x) || modulo(a.y - b.y))
	{
		mlx_pixel_put(mlx_ptr, win_ptr, a.x + 800, a.y + 400, color);
		a.x += step_x;
		a.y += step_y;
		if ((int)a.x > 2000 || (int)a.y > 1000)
			break ;
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
		while (1)
		{
			if (matrix[y+1])
				drow(matrix[y][x], matrix[y+1][x], 20);
			if (matrix[y][x].end)
				drow(matrix[y][x], matrix[y][x+1], 20);
			if (!matrix[y][x].end)
				break ;
			x++;
		}
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
// 	j.x = 100;
// 	j.y = 100;
// 	i.x = 300;
// 	i.y = 80;

// 	drow(i, j, 1);
// 	mlx_key_hook(win_ptr, deal_key, NULL);
// 	mlx_loop(mlx_ptr);
// }
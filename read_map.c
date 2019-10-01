/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:19:57 by Nik               #+#    #+#             */
/*   Updated: 2019/09/30 19:22:44 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_dots_from_line(char *line, t_dot **matrix_of_dots, int y)
{
	char	**dots;
	int		x;

	dots = ft_strsplit(line, ' ');
	x = 0;
	while (dots[x])
	{
		(matrix_of_dots[y][x]).z = (float)ft_atoi(dots[x]) * 40;
		(matrix_of_dots[y][x]).x = x;
		(matrix_of_dots[y][x]).y = y;
		(matrix_of_dots[y][x]).end = 1;
		x++;
	}
	(matrix_of_dots[y][--x]).end = 0;
	return (x);
}

t_dot	**memory_allocete(char *file_name)
{
	t_dot	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	x = ft_wdcounter(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		free(line);
		y++;
	}
	new = (t_dot **)malloc(sizeof(t_dot *) * y);
	while (y > 0)
		new[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
	close(fd);
	return (new);
}

t_dot	**read_map(char *file_name)
{
	t_dot	**matrix_of_dots;
	int		y;
	int		fd;
	char	*line;

	matrix_of_dots = memory_allocete(file_name);
	fd  = open(file_name, O_RDONLY, 0);
	y = 0;
	while (get_next_line(fd, &line))
	{
		get_dots_from_line(line, matrix_of_dots, y);
		y++;
	}
	matrix_of_dots[y] = NULL;
	close(fd);
	return (matrix_of_dots);
}

// int main()
// {
// 	char *name = "test_maps/42.fdf";
// 	t_dot **matrix = read_map(name);
// 	int y;
// 	int x;

// 	y = 0;
// 	while (matrix[y])
// 	{
// 		x = 0;
// 		while (matrix[y][x].end)
// 		{
// 			// ft_printf("%d%d%d ", matrix[y][x].x, matrix[y][x].y, matrix[y][x].z);
// 			ft_printf("%3d", matrix[y][x].z);
// 			x++;
// 		}
// 		ft_printf("\n");
// 		y++;
// 	}
// return (0);
// }
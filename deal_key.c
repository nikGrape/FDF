/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 00:55:04 by Nik               #+#    #+#             */
/*   Updated: 2019/10/01 02:34:04 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int		is_key(int key)
{
	return (key == '+' || key == '/' || key == '*' || key == '!' ||\
	key == '~' || key == '}' || key == '{' || key == '|' ||\
	key == '1' || key == '0' || key == ',');
}

void	do_key(int key, t_dot **matrix)
{
	if (key == '+')//<
		PRM.scale -= 3;
	if (key == '/')//>
		PRM.scale += 3;
	if (key == '*')// '\'
		PRM.z_scale += 1;
	if (key == '!')// {
		PRM.z_scale -= 1;
	//targets
	if (key == '~')//up
		PRM.shift_y -= 10;
	if (key == '}')//down
		PRM.shift_y += 10;
	if (key == '{')//left
		PRM.shift_x -= 10;
	if (key == '|')//right
		PRM.shift_x += 10;
	//****
	if (key == '1')//spase
		PRM.is_isometric = (PRM.is_isometric) ? 0 : 1;

	if (key == '0')//tab
		PRM.angle += 0.05;
	if (key == ',')//'/'
		PRM.angle -= 0.05;
}

int		deal_key(int key, t_dot **matrix)
{
	if (is_key(key))
	{
		mlx_clear_window(PRM.mlx_ptr, PRM.win_ptr);
		do_key(key, matrix);
		draw(matrix);
	}
	if (key == '5')
		exit (0);
	return (0);
}
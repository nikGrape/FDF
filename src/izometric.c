/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   izometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 22:20:39 by Nik               #+#    #+#             */
/*   Updated: 2019/10/01 02:43:17 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	default angle: 0.523599
**	make the figure 3d (isometric stile)
*/

#include "fdf.h"

void	isometric(t_dot *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}

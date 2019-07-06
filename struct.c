/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:29:59 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/04 15:47:13 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_dot
{
	int y;
	int x;
	struct s_dot *next;

}				t_dot;

t_dot	*new_dot(int x, int y)
{
	t_dot *new;

	new->x = x;
	new->y = y;
	return (new);
}

void	f1(t_dot d)
{
	d.x *= 2;
	d.y *= 2;
}

int		main()
{
	t_dot d1;
	t_dot *d2;

	d1.x = 5;
	d1.y = 10;

	(*d2).x = 5;
	d2->x = 5;

	f1(d1);
	printf("x = %d\ny = %d\n", d1.x, d1.y);
}
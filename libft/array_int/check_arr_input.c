/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arr_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:14:29 by Nik               #+#    #+#             */
/*   Updated: 2019/08/31 15:36:26 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

static int	is_number(char *s)
{
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int			check_arr_input(char *nbr)
{
	if (!is_number(nbr) || !ft_isinteger(nbr))
		return (1);
	return (0);
}

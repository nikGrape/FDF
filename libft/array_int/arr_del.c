/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:38:32 by Nik               #+#    #+#             */
/*   Updated: 2019/08/31 16:57:59 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

static void	del_nbr(int *arr, int index)
{
	if (index < ARR_LEN && index >= 0)
	{
		index++;
		while (index < ARR_LEN)
		{
			arr[index] = arr[index + 1];
			index++;
		}
		ARR_LEN--;
	}
}

void		arr_del(int *arr, int index, ...)
{
	va_list	ap;
	int		ind;
	int		i;

	va_start(ap, index);
	del_nbr(arr, index);
	i = 1;
	while ((ind = va_arg(ap, int)))
	{
		del_nbr(arr, ind - i);
		i++;
	}
	va_end(ap);
}

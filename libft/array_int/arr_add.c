/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:10:56 by Nik               #+#    #+#             */
/*   Updated: 2019/08/31 17:10:10 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

void	arr_add(int **arr, int index, int nbr)
{
	int		*new;

	if (index <= *ARR_LEN && index >= 0)
	{
		new = (int *)malloc(sizeof(int) * (*ARR_LEN + 4));
		arr_copy(new, *arr);
		new[0]++;
		arr_set(new, index, nbr);
		while (++index <= *ARR_LEN)
			arr_set(new, index, (*arr)[index]);
		free(*arr);
		*arr = new;
	}
}

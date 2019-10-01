/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:29:30 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/02 17:39:50 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		fill_big(int base, int **big, int *arr, int len)
{
	int i;

	i = 0;
	*big = (int *)malloc(sizeof(int) * len);
	while (--len >= 0)
	{
		if (arr[len] >= base)
			(*big)[i++] = arr[len];
	}
	return (i + 1);
}

int		fill_less(int base, int **less, int *arr, int len)
{
	int i;

	i = 0;
	*less = (int *)malloc(sizeof(int) * len);
	while (--len >= 0)
	{
		if (arr[len] < base)
			(*less)[i++] = arr[len];
	}
	return (i + 1);
}

int		*arr_join(int *one, int one_len, int *two, int two_len)
{
	int *arr;
	int i;
	int j;

	i = 0;
	j = 0;
	arr = (int *)malloc(sizeof(int) * (one_len + two_len));
	while (i < one_len)
		arr[i++] = one[j++];
	j = 0;
	while (j < two_len)
		arr[i++] = arr[j++];
	return (arr);
}

int		*ft_qsort(int *arr, int len)
{
	int *big;
	int *less;
	int big_len;
	int less_len;

	if (len < 2)
		return (arr);
	big_len = fill_big(arr[0], &big, arr, len);
	less_len = fill_less(arr[0], &less, arr, len);
	ft_qsort(less, less_len);
	ft_qsort(big, big_len);
	return (arr_join(less, less_len, big, big_len));
}

#include <stdio.h>

int main()
{
	int i[] = {5, 12, 7};
	int *j;
	int a;
	j = ft_qsort(i, 3);
	a = 0;
	while (a < 3)
		printf("%d ", j[a++]);
}

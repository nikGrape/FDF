/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 01:15:13 by vinograd          #+#    #+#             */
/*   Updated: 2019/05/14 19:27:36 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *restrict dst, void *restrict src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char*)dst)[i] = *(char*)src;
		src++;
		i++;
	}
	return (dst);
}

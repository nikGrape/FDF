/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:24:00 by vinograd          #+#    #+#             */
/*   Updated: 2019/05/06 11:24:56 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *temp;

	temp = (char *)malloc(size);
	if (temp == NULL || size == 0)
		return (NULL);
	ft_bzero(temp, size);
	return ((void *)temp);
}

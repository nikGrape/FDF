/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:20:16 by vinograd          #+#    #+#             */
/*   Updated: 2019/05/10 13:35:13 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void const *src, size_t len)
{
	void	*dst;
	size_t	i;

	i = 0;
	if ((dst = malloc(len)) == NULL)
		return (NULL);
	while (i < len)
	{
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	return (dst);
}

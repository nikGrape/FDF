/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:11:09 by vinograd          #+#    #+#             */
/*   Updated: 2019/05/14 19:28:27 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *p_dst;
	unsigned char *p_src;

	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	if (dst >= src)
		while (len--)
			p_dst[len] = p_src[len];
	else
		while (len--)
		{
			*p_dst = *p_src;
			p_src++;
			p_dst++;
		}
	return (dst);
}

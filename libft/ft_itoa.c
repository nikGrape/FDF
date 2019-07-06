/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:32:09 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/28 18:14:47 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int i)
{
	int size;

	if (i == 0)
		return (2);
	size = 1;
	if (i < 0)
	{
		i /= 10;
		size += 2;
		i = -i;
	}
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int nbr)
{
	char	*str;
	int		len;
	int		sign;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	len = size(nbr);
	sign = 0;
	if (nbr < 0)
	{
		sign = 1;
		nbr = -nbr;
	}
	if ((str = (char *)malloc(len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (--len >= sign)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

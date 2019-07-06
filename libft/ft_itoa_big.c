/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:28:12 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/29 19:49:34 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_unsigned(size_t nbr)
{
	char ch;
	char *str;

	str = NULL;
	if (nbr >= 10)
		str = ft_itoa_unsigned(nbr / 10);
	ch = nbr % 10 + '0';
	return (ft_stradd(str, ch));
}

char		*ft_itoa_long(long nbr)
{
	if (nbr < 0)
		return (ft_strjoin_free("-", ft_itoa_unsigned(-nbr), 2));
	else
		return (ft_itoa_unsigned(nbr));
}

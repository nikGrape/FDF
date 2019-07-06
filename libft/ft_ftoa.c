/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:27:57 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/02 13:00:30 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	approximator(char *fract, double nbr)
{
	int apr;
	int i;
	
	i = ft_strlen(fract);
	nbr *= 10;
	apr = (int)nbr;
	apr %= 10;
	if (apr >= 5)
		while (i)
		{
			if (fract[--i] != '9')
				{
					fract[i] += 1;
					return (0);
				}
			else
				fract[i] = '0';			
		}
	else
		return (0);
	return (1);
}

char		*ft_ftoa_long(long double nbr, unsigned int precision)
{
	int			i;
	size_t		whole;
	char		fract[500];
	int			sign;
	char		ch;

	ch = (precision) ? '.' : '\0';
	sign = (nbr < 0) ? -1 : 1;
	nbr = nbr * sign;
	whole = (size_t)nbr;
	nbr -= whole;
	i = 0;
	while (precision--)
	{
		nbr *= 10;
		fract[i++] = nbr + '0';
		nbr -= (int)nbr;
	}
	fract[i] = '\0';
	whole += approximator(fract, nbr);	
	return (sign < 0) ? ft_strjoin_free("-", ft_strjoin_free\
	(ft_stradd(ft_itoa_unsigned(whole), ch), fract, 1), 2)\
	: ft_strjoin_free(ft_stradd(ft_itoa_unsigned(whole), ch), fract, 1);
}

char		*ft_ftoa(double nbr, unsigned int precision)
{
	return (ft_ftoa_long(nbr, precision));
}

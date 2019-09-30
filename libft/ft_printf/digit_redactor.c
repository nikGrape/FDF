/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_redactor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 10:40:30 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/15 11:30:27 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hashtag_redactor(register int specifier, char *arg, short width)
{
	if (!ft_strcmp(arg, "0") && specifier != 'p')
		return (arg);
	if (!ft_strcmp(arg, "0") && specifier == 'p' && !width)
		arg[0] = '\0';
	if (specifier == 'x' || specifier == 'p')
		return (ft_strjoin_free("0x", arg, 2));
	else if (specifier == 'o')
		return (ft_strjoin_free("0", arg, 2));
	return (arg);
}

static char	*width_redactor(char *arg, char *dash, t_flag flags)
{
	int		len;
	char	*str;
	char	*dot;

	dot = ft_strchr(arg, '.');
	if (flags.spcf != 'f' || !dot)
	{
		len = ft_strlen(arg);
		len = (dash) ? len - 1 : len;
	}
	else
		len = ft_strlen(dot) - 1;
	if (flags.width > len)
	{
		str = ft_strnew(flags.width - len);
		ft_memset(str, '0', flags.width - len);
		str = (flags.spcf != 'f') ? ft_strjoin_free(str, arg, 3)\
		: ft_strjoin_free(arg, str, 3);
		if (dash)
			ft_swap(ft_strchr(str, '-'), str);
		return (str);
	}
	return (arg);
}

static char	*length_redactor(char *arg, register t_flag flags, int len)
{
	char			*str;
	char			*dash;

	dash = ft_strchr(arg, '-');
	if (len < flags.length)
	{
		str = ft_strnew(flags.length - len);
		ft_memset(str, flags.filler, flags.length - len);
		if (flags.spcf == 'd' && flags.spase && flags.filler == '0' && !dash)
			str[0] = ' ';
		arg = (flags.minus || flags.spcf == 'p') ?\
		ft_strjoin_free(arg, str, 3) : ft_strjoin_free(str, arg, 3);
		dash = ft_strchr(arg, '-');
		if (dash && flags.filler == '0')
			ft_swap(arg, dash);
		if (flags.hashtag && flags.filler == '0' && (str = ft_strchr(arg, 'x')))
			ft_swap(str, arg + 1);
		if (!dash && flags.plus && flags.filler == '0' &&\
		(flags.spcf == 'd' || flags.spcf == 'f'))
			ft_swap(ft_strchr(arg, '0'), ft_strchr(arg, '+'));
	}
	else if (flags.spase && (flags.spcf == 'd' || flags.spcf == 'f') && !dash)
		arg = ft_strjoin_free(" ", arg, 2);
	return (arg);
}

char		*redactor(char *arg, t_flag flags, register char spcf)
{
	char			*dash;

	flags.spcf = spcf;
	dash = ft_strchr(arg, '-');
	arg = width_redactor(arg, dash, flags);
	if (flags.hashtag || spcf == 'p')
		arg = hashtag_redactor(spcf, arg, flags.width);
	if (!flags.width && !ft_strcmp(arg, "0") &&\
	(spcf == 'x' || spcf == 'o' || spcf == 'd')\
	&& !(flags.hashtag && spcf == 'o'))
		arg[0] = '\0';
	if (!dash && flags.plus && (spcf == 'd' || spcf == 'f'))
		arg = ft_strjoin_free("+", arg, 2);
	flags.filler = (flags.width != -1 && spcf != 'f') ? ' ' : flags.filler;
	arg = length_redactor(arg, flags, ft_strlen(arg));
	return (arg);
}

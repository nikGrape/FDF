/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 00:55:21 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/30 14:03:18 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hendler_s_c(t_flag *flags, va_list *ap)
{
	char *s;
	char ch;

	s = NULL;
	if (flags->spcf == 's')
	{
		s = va_arg(*ap, char *);
		s = (s) ? str_redactor(ft_strdup(s), *flags) :\
		str_redactor(ft_strdup("(null)"), *flags);
	}
	else if (flags->spcf == 'c')
	{
		ch = (char)va_arg(*ap, int);
		if (ch)
			s = str_redactor(ft_stradd(NULL, ch), *flags);
		else
			s = str_redactor(ft_strdup(""), *flags);
	}
	return (s);
}

static char	*hendler_f_x(t_flag flags, va_list *ap)
{
	char *s;

	s = NULL;
	if (flags.spcf == 'f')
	{
		flags.width = (flags.width == -1) ? 6 : flags.width;
		if (flags.ld_flag)
			s = redactor(ft_ftoa_long(va_arg(*ap, long double),\
			flags.width), flags, 'f');
		else
			s = redactor(ft_ftoa(va_arg(*ap, double), flags.width), flags, 'f');
	}
	else if (flags.spcf == 'X' || flags.spcf == 'x')
	{
		s = (flags.j_flag || flags.l_flag) ?\
		redactor(ft_itoa_base_unsigned(va_arg(*ap, size_t), 16), flags, 'x')\
		: redactor(ft_itoa_base(va_arg(*ap, int), 16), flags, 'x');
		if (flags.spcf == 'X')
			ft_strupper(s);
	}
	return (s);
}

static char	*hendler_d_i_u(register t_flag flags, va_list *ap)
{
	char *s;

	s = NULL;
	if (flags.spcf == 'd' || flags.spcf == 'i')
	{
		if (flags.h_flag == 1)
			s = ft_itoa((short)va_arg(*ap, int));
		else if (flags.h_flag == 2)
			s = ft_itoa((signed char)va_arg(*ap, int));
		else if (flags.l_flag || flags.j_flag || flags.z_flag)
			s = ft_itoa_long(va_arg(*ap, long));
		else
			s = ft_itoa(va_arg(*ap, int));
		s = redactor(s, flags, 'd');
	}
	else if (flags.spcf == 'u' || flags.spcf == 'U')
	{
		if (flags.spcf == 'U' || flags.l_flag || flags.j_flag || flags.z_flag)
			s = ft_itoa_unsigned(va_arg(*ap, unsigned long));
		else
			s = ft_itoa_unsigned(va_arg(*ap, unsigned int));
		s = redactor(s, flags, 'u');
	}
	return (s);
}

char		*specifier(t_flag *flags, va_list *ap)
{
	char *s;

	s = NULL;
	if (flags->spcf == 's' || flags->spcf == 'c')
		s = hendler_s_c(flags, ap);
	else if (flags->spcf == 'd' || flags->spcf == 'i' |\
	flags->spcf == 'u' || flags->spcf == 'U')
		s = hendler_d_i_u(*flags, ap);
	else if (flags->spcf == 'X' || flags->spcf == 'x' || flags->spcf == 'f')
		s = hendler_f_x(*flags, ap);
	else if (flags->spcf == 'b')
		s = redactor(ft_itoa_base(va_arg(*ap, int), 2), *flags, 'o');
	else if (flags->spcf == 'o')
		s = redactor(ft_itoa_base(va_arg(*ap, int), 8), *flags, 'o');
	else if (flags->spcf == 'p')
		s = redactor(ft_itoa_base_unsigned(va_arg(*ap, size_t), 16),\
		*flags, 'p');
	else if (flags->spcf == '%')
		s = str_redactor(ft_strdup("%"), *flags);
	else if (flags->spcf == '\0')
		return (NULL);
	else
		s = str_redactor(ft_strdup(""), *flags);
	return (s);
}

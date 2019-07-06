/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:07:55 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/02 13:22:41 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>

typedef struct	s_flags
{
	short			width;
	unsigned short	length;
	unsigned short	steps;
	unsigned char	spcf;
	unsigned char	filler;
	unsigned char	hashtag;
	unsigned char	minus;
	unsigned char	spase;
	unsigned char	plus;
	unsigned char	zero;
	unsigned char	l_flag;
	unsigned char	h_flag;
	unsigned char	j_flag;
	unsigned char	z_flag;
}				t_flag;

t_flag			flag_analazer(const char *s);
char			*specifier(register char ch, t_flag flags, va_list *ap);
char			*redactor(char *arg, t_flag flags, register char spcf);
char			*str_redactor(char *arg, register t_flag flags);

#endif

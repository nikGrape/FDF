/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_analazer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:05:39 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/02 13:30:32 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_flag(register char ch)
{
	if (ch == ' ' || ch == '#' || ch == '+'\
	|| ch == '-' || ch == '0')
		return (1);
	return (0);
}

static t_flag	flag_analazer_first(const char *s)
{
	t_flag flags;

	ft_bzero(&flags, sizeof(t_flag));
	flags.width = -1;
	while (is_flag(s[flags.steps]))
	{
		if (s[flags.steps] == '#')
			flags.hashtag = 1;
		if (s[flags.steps] == '-')
			flags.minus = 1;
		if (s[flags.steps] == ' ')
			flags.spase = 1;
		if (s[flags.steps] == '+')
			flags.plus = 1;
		if (s[flags.steps] == '0')
			flags.zero = 1;
		flags.steps++;
	}
	if (flags.minus)
		flags.zero = 0;
	if (flags.plus)
		flags.spase = 0;
	flags.filler = (flags.zero) ? '0' : ' ';
	return (flags);
}

static void		flag_analazer_second(t_flag *flags, const char *s)
{
	while (s[flags->steps] == 'l' || s[flags->steps] == 'L')
	{
		flags->l_flag = 1;
		flags->steps++;
	}
	while (s[flags->steps] == 'h')
	{
		flags->h_flag++;
		flags->steps++;
	}
	if (s[flags->steps] == 'j')
	{
		flags->j_flag = 1;
		flags->steps++;
	}
	if (s[flags->steps] == 'z')
	{
		flags->z_flag = 1;
		flags->steps++;
	}
}

t_flag			flag_analazer(const char *s)
{
	t_flag flags;

	flags = flag_analazer_first(s);
	if (s[flags.steps] >= '1' && s[flags.steps] <= '9')
	{
		flags.length = ft_atoi(&s[flags.steps]);
		while (s[flags.steps] >= '0' && s[flags.steps] <= '9')
			flags.steps++;
	}
	if (s[flags.steps] == '.')
	{
		flags.width = ft_atoi(&s[++flags.steps]);
		while (s[flags.steps] >= '0' && s[flags.steps] <= '9')
			flags.steps++;
	}
	flag_analazer_second(&flags, s);
	return (flags);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_redactor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:19:09 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/20 14:51:32 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BLACK		"\033[0;30m"
#define BOLD_GRAY	"\033[1;30m"
#define RED			"\033[0;31m"
#define BOLD_RED	"\033[1;31m"
#define GREEN		"\033[0;32m"
#define BOLD_GREEN	"\033[1;32m"
#define YELLOW		"\033[0;33m"
#define BOLD_YELLOW	"\033[01;33m"
#define BLUE		"\033[0;34m"
#define BOLD_BLUE	"\033[1;34m"
#define MAGENTA		"\033[0;35m"
#define BLD_MAGENTA	"\033[1;35m"
#define CYAN		"\033[0;36m"
#define BOLD_CYAN	"\033[1;36m"
#define EOC			"\033[0m"

static int	color_compare2(char *color)
{
	int i;

	i = 0;
	if (!ft_strcmp("magenta", color))
		i = ft_putstr(MAGENTA);
	if (!ft_strcmp("bold_magenta", color))
		i = ft_putstr(BLD_MAGENTA);
	else if (!ft_strcmp("cyan", color))
		i = ft_putstr(CYAN);
	else if (!ft_strcmp("bold_cyan", color))
		i = ft_putstr(BOLD_CYAN);
	else if (!ft_strcmp("black", color))
		i = ft_putstr(BLACK);
	else if (!ft_strcmp("bold_gray", color))
		i = ft_putstr(BOLD_GRAY);
	else if (!ft_strcmp("eoc", color))
		i = ft_putstr(EOC);
	return (i);
}

static int	color_compare(char *color)
{
	int i;

	i = 0;
	if (!ft_strcmp("red", color))
		i = ft_putstr(RED);
	else if (!ft_strcmp("bold_red", color))
		i = ft_putstr(BOLD_RED);
	else if (!ft_strcmp("green", color))
		i = ft_putstr(GREEN);
	else if (!ft_strcmp("bold_green", color))
		i = ft_putstr(BOLD_GREEN);
	else if (!ft_strcmp("yellow", color))
		i = ft_putstr(YELLOW);
	else if (!ft_strcmp("bold_yellow", color))
		i = ft_putstr(BOLD_YELLOW);
	else if (!ft_strcmp("blue", color))
		i = ft_putstr(BLUE);
	else if (!ft_strcmp("bold_blue", color))
		i = ft_putstr(BOLD_BLUE);
	else
		i = color_compare2(color);
	return (i);
}

int			color_redactor(const char *str)
{
	char	*color;
	char	*brace;
	int		i;

	if (!(brace = ft_strchr(str++, '}')))
		return (0);
	color = ft_strsub(str, 0, brace - str);
	i = color_compare(color);
	i = (i) ? ft_strlen(color) + 2 : 0;
	ft_strdel(&color);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:56:03 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/17 20:45:38 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_arr	*newlist(const int fd)
{
	t_arr	*new;

	if (!(new = (t_arr *)malloc(sizeof(t_arr))))
		return (NULL);
	new->fd = fd;
	new->rest = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

static char		*checkrest(char **p_n, char *rest)
{
	char *str;

	if ((*p_n = ft_strchr(rest, '\n')) != NULL)
	{
		str = ft_strsub(rest, 0, *p_n - rest);
		ft_strcpy(rest, ++(*p_n));
	}
	else
	{
		str = ft_strnew(ft_strlen(rest) + 1);
		ft_strcat(str, rest);
		ft_strclr(rest);
	}
	return (str);
}

static int		get_line(const int fd, char **line, char *rest)
{
	char			buf[BUFF_SIZE + 1];
	char			*p_n;
	char			*tmp;
	int				rd;

	p_n = NULL;
	rd = 1;
	*line = checkrest(&p_n, rest);
	while (p_n == 0 && ((rd = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[rd] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(rest, ++p_n);
			ft_strclr(--p_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || rd < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(rest) || rd) ? 1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	static t_arr	*list;
	t_arr			*tmp;
	int				ret;

	if (fd < 0 || line == 0)
		return (-1);
	if (!list)
		list = newlist(fd);
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = newlist(fd);
		tmp = tmp->next;
	}
	ret = get_line(fd, line, tmp->rest);
	return (ret);
}

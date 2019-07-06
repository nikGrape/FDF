/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:18:15 by vinograd          #+#    #+#             */
/*   Updated: 2019/05/10 13:49:41 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *lnext;

	if (alst != NULL)
	{
		tmp = *alst;
		lnext = *alst;
		while (tmp != NULL)
		{
			(*del)(tmp->content, tmp->content_size);
			tmp = lnext->next;
			free(lnext);
			lnext = tmp;
		}
		*alst = NULL;
	}
}

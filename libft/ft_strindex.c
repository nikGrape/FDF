/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:50:51 by vinograd          #+#    #+#             */
/*   Updated: 2019/05/14 14:16:39 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strindex(char *haystack, char *needle)
{
	int i;
	int j;
	int n;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		n = i;
		while (needle[j] == haystack[n])
		{
			if (needle[j + 1] == '\0')
				return (i);
			n++;
			j++;
		}
		i++;
	}
	return (-1);
}

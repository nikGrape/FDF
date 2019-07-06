/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:25:48 by vinograd          #+#    #+#             */
/*   Updated: 2019/05/01 19:26:54 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystach, const char *needle)
{
	int i;
	int j;
	int n;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystach);
	while (haystach[i])
	{
		j = 0;
		n = i;
		while (haystach[n] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char*)&haystach[i]);
			j++;
			n++;
		}
		i++;
	}
	return (0);
}

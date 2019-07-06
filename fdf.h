/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:13:39 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/05 19:24:44 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MAX(x, y) (x > y) ? x : y;
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct	s_dot
{
	float			x;
	float			y;
	float			z;
	struct s_dot	*next;
}				t_dot;

void			ft_errors(int i);

#endif

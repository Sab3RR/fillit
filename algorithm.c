/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:58:33 by seshevch          #+#    #+#             */
/*   Updated: 2018/11/29 14:26:57 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_alpha(char **str, int i, int k, t_ttrmn *el)
{
	int		f;
	int		s;
	int		count;

	f = el->xy[0][0];
	s = el->xy[0][1];
	count = 0;
	el->h = 0;
	while (count != 4 && (i + el->xy[el->h][0] - f) < g_d &&
			str[i + el->xy[el->h][0] - f][k + el->xy[el->h][1] - s] == '.')
	{
		el->h++;
		count++;
	}
	if (count == 4)
	{
		el->i1 = i;
		el->k1 = k;
		while (--count >= 0)
			str[i + el->xy[count][0] - f]
				[k + el->xy[count][1] - s] = el->letter;
		return (1);
	}
	else
		return (0);
}

void		ft_erase(t_ttrmn *lst, char **str)
{
	int		f;
	int		s;

	f = lst->xy[0][0];
	s = lst->xy[0][1];
	lst->h = 0;
	while (lst->h < 4)
	{
		str[lst->i1 + lst->xy[lst->h][0] - f]
			[lst->k1 + lst->xy[lst->h][1] - s] = '.';
		lst->h++;
	}
}

void		ft_next_coord(int *i, int *k)
{
	if (*k + 1 == g_d)
	{
		(*i)++;
		*k = 0;
	}
	else
		(*k)++;
}

int			ft_super_alpha(char **str, int i, int k, t_ttrmn *lst)
{
	g_t = 0;
	if (lst->letter == 'A' && i == (g_d - 1) && k == (g_d - 1))
		return (0);
	else
	{
		while ((i < g_d && k < g_d) && ((g_t = ft_alpha(str, i, k, lst)) == 0))
			ft_next_coord(&i, &k);
		if (g_t == 1)
		{
			if (lst->next)
			{
				if (ft_super_alpha(str, 0, 0, lst->next) == 1)
					return (1);
				else
				{
					ft_erase(lst, str);
					ft_next_coord(&i, &k);
					return (ft_super_alpha(str, i, k, lst));
				}
			}
			else
				return (1);
		}
		return (0);
	}
}

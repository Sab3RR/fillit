/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:06:20 by rkulahin          #+#    #+#             */
/*   Updated: 2018/12/06 10:26:36 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int			count_touch(char **arr)
{
	int		i;
	int		j;
	int		counter;

	i = -1;
	counter = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (arr[i][j] == '#')
			{
				if ((i + 1) < 4 && arr[i + 1][j] == '#')
					counter++;
				if ((i - 1) >= 0 && arr[i - 1][j] == '#')
					counter++;
				if ((j + 1) < 4 && arr[i][j + 1] == '#')
					counter++;
				if ((j - 1) >= 0 && arr[i][j - 1] == '#')
					counter++;
			}
		}
	}
	return (counter);
}

void		count_dh(char **arr)
{
	int counter_d;
	int	counter_h;
	int	i;
	int	j;

	i = 0;
	counter_d = 0;
	counter_h = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] == '.')
				counter_d++;
			else if (arr[i][j] == '#')
				counter_h++;
			j++;
		}
		i++;
	}
	i = count_touch(arr);
	if (counter_d != 12 || counter_h != 4 || (i != 6 && i != 8))
		f_error();
}

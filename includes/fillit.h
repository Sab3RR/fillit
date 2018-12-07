/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:16:18 by rkulahin          #+#    #+#             */
/*   Updated: 2018/11/30 15:50:48 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>


typedef struct		s_tet
{
	int				coords[4][2];
	char			letter;
	struct s_tet	*next;
}					t_tet;


void				f_error(void);
void				f_read(int fd, t_tet *node);
void				count_dh(char **arr);
int					count_touch(char **arr);


#endif

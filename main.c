/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 09:58:45 by rkulahin          #+#    #+#             */
/*   Updated: 2018/12/07 15:41:05 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include "GNL/get_next_line.h"
#include "libft/libft.h"

void	free_arr(char **map, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(map[i]);
	free(map);
}

void	print_map(long size[2])
{
	int		i;
	int		j;
	char	**map;

	map = (char **)size[1];
	i = -1;
	while (++i < size[0])
	{
		j = -1;
		while (++j < size[0])
		{
			if (map[i][j] == 0)
				write(1, ".", 1);
			else
				write(1, &map[i][j], 1);
		}
		write(1, "\n", 1);
	}
}

void		dell_tet(t_tet *node, int NumOfTetramina, long size[2])
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	while (++i < NumOfTetramina)
		node = node->next;
	i = 0;
	map = (char **)size[1];
	while (i < size[0])
	{
		j = 0;
		while (j < size[0])
		{
			if (map[i][j] == node->letter)
				map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void			add_tet(t_tet *node, const int *coords, int index, long siz[2])
{
	int		i;
	t_tet	*tmp;
	char	**map;
	int		c[2];

	c[0] = coords[0];
	c[1] = coords[1];
	tmp = node;
	map = (char **)siz[1];
	i = 0;
	while (tmp->next)
	{
		if (tmp->letter == 'A' + index)
			break ;
		tmp = tmp->next;
	}
	while (i < 4)
	{
		if (i > 0)
		{
			c[0] = c[0] + (tmp->coords[i][0] - tmp->coords[i - 1][0]);
			c[1] = c[1] + (tmp->coords[i][1] - tmp->coords[i - 1][1]);
		}
		map[c[0]][c[1]] = tmp->letter;
		i++;
	}
}

int			put_tet(t_tet *node, const int *coords, int index, long *siz)
{
	int		i;
	long	size;
	t_tet	*tmp;
	char	**map;
	int		c[2];

	c[0] = coords[0];
	c[1] = coords[1];
	tmp = node;
	size = siz[0];
	map = (char **)siz[1];
	i = 0;
	while (tmp->next)
	{
		if (tmp->letter == 'A' + index)
			break ;
		tmp = tmp->next;
	}
	while (i < 4)
	{
		if (i > 0)
		{
			c[0] = c[0] + (tmp->coords[i][0] - tmp->coords[i - 1][0]);
			c[1] = c[1] + (tmp->coords[i][1] - tmp->coords[i - 1][1]);
		}
		if ((c[0] < 0 || c[0] >= size) || (c[1] < 0 || c[1] >= size))
			return (0);
		else if(map[c[0]][c[1]] != 0)
			return (0);
		i++;
	}
	return (1);
}

int			min_map(t_tet *node)
{
	int		i;
	int		j;
	t_tet	*tmp;

	i = 0;
	j = 2;
	tmp = node;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	i = i * 4;
	while (j < i)
	{
		if (j * j >= i)
			return (j);
		j++;
	}
	return (0);
}

t_tet		*find_tet(t_tet *node)
{
	char	letter;
	t_tet	*tmp;

	tmp = node;
	if (node && !node->next)
	{
		tmp->next = (t_tet *)malloc(sizeof(t_tet));
		tmp->next->next = NULL;
		return (tmp);
	}
	letter = tmp->letter;
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp->letter = ++letter;
	}
	tmp->next = (t_tet *)malloc(sizeof(t_tet));
	tmp->next->next = NULL;
	return (tmp);
}

void		find_coord(char **arr, int coords[4][2])
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (arr[i][j] == '#')
			{
				coords[k][1] = j;
				coords[k][0] = i;
				k++;
			}
		}
	}
}

int			*coord_in_map(t_tet *node, int NumOfTetramina, long size[2])
{
	int *coords;
	int	i;
	int	j;
	char **map;

	coords = (int*)malloc(sizeof(int) * 2);
	map = (char**)size[1];
	while (node->next)
	{
		if (node->letter == 'A' + NumOfTetramina)
			break ;
		node = node->next;
	}
	i = 0;
	while (i < size[0])
	{
		j = 0;
		while (j < size[0])
		{
			if (map[i][j] == node->letter)
			{
				coords[1] = j + 1;
				coords[0] = i;
				return (coords);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void		**malloc_array(size_t col, size_t row, size_t size)
{
	void	**arr;
	size_t		i;

	i = 0;

	arr = malloc(sizeof(void *) * row);
	while (i != col)
	{
		arr[i] = malloc((size_t) (size * col));
		i++;
	}
	return (arr);
}

void		f_error(void)
{
	write(2, "error\n", 6);
	system("leaks -q fillit");
	exit(1);
}

void		f_read(int fd, t_tet *node)
{
	int		i;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * 5);
	i = 0;
	while ((get_next_line(fd, &arr[i])) == 1)
	{
		if (i == 4)
		{
			if (arr[i][0] == '\0')
			{
				count_dh(arr);
				find_coord(arr, find_tet(node)->coords);
				free_arr(arr, 5);
				arr = (char **)malloc(sizeof(char *) * 5);
				i = -1;
			}
			else
				f_error();
		}
		else if (ft_strlen(arr[i]) != 4)
			f_error();
		i++;
	}
	if (arr[0] == NULL)
		f_error();
	count_dh(arr);
	find_coord(arr, find_tet(node)->coords);
	free_arr(arr, 5);
}
char		**malloc_map(size_t size)
{
	char	**map;
	int		i;
	int		j;

	if (!(map = (char **)malloc_array(size, size, sizeof(char))))
		f_error();
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map[i][j] = 'a';
			j++;
		}
		i++;
	}
	return (map);
}

void	free_map(int **map, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(map[i]);
	free(map);
}

int		size_list(t_tet *node)
{
	int		i;
	t_tet   *list;

	list = node;
	i = 0;
	while (list->next)
	{
		i++;
		list = list->next;
	}
	return (i);	
}

int counter = 0;

int		recursive_algoritm(t_tet *node, int *coords, int NumOfTetramina, long *size)
{
//	if (counter == 131047)
	if (counter == 104836)
		write(0, 0, 0);
	counter++;
	if (NumOfTetramina >= size_list(node)) // just think about it
		return (1);
	else if (coords[1] >= (int)size[0])
	{
		coords[1] = 0;
		coords[0]++;
		if (recursive_algoritm(node, coords, NumOfTetramina, size))
			return (1);
		return (0);
	}
	else if (coords[0] >= (int)size[0])
	{
		coords = coord_in_map(node, NumOfTetramina - 1, size);
		dell_tet(node, NumOfTetramina - 1, size);
		print_map(size);
		if (recursive_algoritm(node, coords, NumOfTetramina - 1, size))
			return (1);
		return (0);
	}
	else if (NumOfTetramina < 0)
	{
		//free_map((int **)size[1], size[0]);
		size[1] = (long)malloc_map((size_t) ++size[0]);
		coords[0] = 0;
		coords[1] = 0;
		if (recursive_algoritm(node, coords, 0, size))
			return (1);
		return (0);
	}
	else
	{
		if (put_tet(node, coords, NumOfTetramina, size))
		{
			add_tet(node, coords, NumOfTetramina, size);
			print_map(size);
			coords[0] = 0;
			coords[1] = 0;

			if (recursive_algoritm(node, coords, ++NumOfTetramina, size))
				return (1);
			return (0);
		}
		else
		{
			coords[1]++;
			if (recursive_algoritm(node, coords, NumOfTetramina, size))
				return (1);
			return (0);
		}
	}
}

int		main(int ac, char **av)
{
	int		fd;
	t_tet	*node;
	long	*size;
	int		*coords;
	int		coords_v2[2]; // just think about it

	// if (ac != 2)
	// {
	// 	ft_putendl("usage: ./fillit source_file");
	// 	exit(1);
	// }
	fd = open("test.fillit", O_RDONLY);
	node = (t_tet *)malloc(sizeof(t_tet));
	node->next = NULL;
	node->letter = 'A';
	f_read(fd, node);

	size = (long *)malloc(2 * sizeof(long));
	size[0] = min_map(node);
	size[1] = (long)malloc_map((size_t) size[0]);

	coords = (int*)malloc(sizeof(int) * 2);
	coords[0] = 0;
	coords[1] = 0;

	if (!recursive_algoritm(node, coords, 0, size))
		exit(1);
	print_map(size);
	return (1);
}

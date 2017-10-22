/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 03:29:30 by ghippoda          #+#    #+#             */
/*   Updated: 2017/05/17 15:54:01 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_init_tmp(t_map *tmp)
{
	tmp->tab = NULL;
	tmp->i = 0;
	tmp->j = 0;
}

int		check_line(int fd, char *str)
{
	int		i;
	int		test;

	i = 0;
	while ((test = get_next_line(fd, &str)))
	{
		if (test == -1)
			return (-1);
		free(str);
		i++;
	}
	return (i);
}

char	**ft_split_by_gnl(int fd, t_map *tmp, char *av)
{
	char	**tab;
	char	*str;
	int		i;

	i = 0;
	str = "";
	tmp->i = check_line(fd, str);
	if (tmp->i == -1)
		errors(1);
	fd = open(av, O_RDONLY);
	if (!(tab = (char**)malloc(sizeof(char*) * (tmp->i + 1))))
		return (0);
	while (get_next_line(fd, &str))
	{
		tab[i] = str;
		i++;
	}
	tab[i] = NULL;
	close(fd);
	return (tab);
}

int		main(int ac, char **av)
{
	int			fd;
	char		**tab;
	t_map		tmp;

	ft_init_tmp(&tmp);
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
	{
		ft_putstr("usage: ./wold3d ./map/map1(2)\n");
		return (0);
	}
	if (ac != 2 || fd < 0 || !(tab = ft_split_by_gnl(fd, &tmp, av[1])))
	{
		ft_putstr("Error\n");
		return (0);
	}
	tmp.i = ft_count_tab(tab);
	tmp.tab = ft_creatmap(tab, &tmp);
	if (tmp.i != tmp.j)
		return (0);
	if (ft_init_param(&tmp) != 0)
		return (0);
	return (0);
}

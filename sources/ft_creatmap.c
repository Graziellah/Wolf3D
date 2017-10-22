/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:22:18 by ghippoda          #+#    #+#             */
/*   Updated: 2017/05/16 19:09:17 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			ft_count_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int			ft_count_word2(char *str, int y)
{
	int		i;
	int		nb;

	nb = ft_count_words(str, ' ');
	i = 0;
	while (i < y)
	{
		if (ft_count_words(str, ' ') == nb)
			i++;
		else
			return (0);
	}
	return (nb);
}

void		ft_creatmap2(int i, int j, int **map, char **tab)
{
	int		count;

	count = 1;
	map[i][j] = ft_atoi(tab[i]);
	while (tab[i][count] != ' ')
		count++;
	tab[i] = ft_strsubf(tab[i], count + 1, ft_strlen(tab[i]));
}

int			**ft_creatmap(char **tab, t_map *tmp)
{
	int		j;
	int		i;
	int		**map;
	int		len;

	i = 0;
	if (!tab || !(map = (int**)malloc(sizeof(tab) * tmp->i)))
		return (NULL);
	len = ft_count_word2(tab[i], tmp->i);
	while (i < tmp->i)
	{
		tmp->j = ft_count_word2(tab[i], tmp->i);
		if (tmp->j != len)
			return (0);
		if (!(map[i] = (int*)malloc(sizeof(tab) * tmp->j)))
			return (NULL);
		j = 0;
		while (j < tmp->j)
		{
			ft_creatmap2(i, j, map, tab);
			j++;
		}
		i++;
	}
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:32:17 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/22 17:44:24 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcmp_pos(const char *s1, const char *s2)
{
	char	*tab;
	int		i;

	i = 0;
	if ((tab = (char*)malloc(sizeof(tab) * 3)) == NULL)
		return (NULL);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			tab[0] = (char)i + '0';
			tab[1] = (char)s1[i];
			tab[2] = (char)s2[i];
			return (tab);
		}
		i++;
	}
	return (NULL);
}

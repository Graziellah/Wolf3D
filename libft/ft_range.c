/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:17:36 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/22 15:20:15 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int		*dest;
	int		i;

	i = 0;
	if (min >= max)
		return (0);
	dest = (int*)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		dest[i] = min;
		i++;
		min++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:59:40 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/25 12:42:16 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	if ((new = malloc(sizeof(*new) * (size))) == NULL)
		return (NULL);
	else
		while (i < size)
		{
			new[i] = 0;
			i++;
		}
	return (new);
}

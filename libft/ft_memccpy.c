/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 05:55:36 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/18 10:31:18 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*tmp_dest;
	char	*tmp_src;
	size_t	i;

	i = 0;
	tmp_dest = (char*)dest;
	tmp_src = (char*)src;
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		if (tmp_dest[i] == c)
			return (&tmp_dest[i] + 1);
		i++;
	}
	return (NULL);
}

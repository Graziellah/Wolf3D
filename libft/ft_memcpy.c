/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:24:23 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/17 15:59:21 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmp;
	char	*tmp_dest;
	size_t	i;

	i = 0;
	tmp_dest = (char*)dest;
	tmp = (char*)src;
	while (i < n)
	{
		tmp_dest[i] = tmp[i];
		i++;
	}
	return ((unsigned char*)dest);
}

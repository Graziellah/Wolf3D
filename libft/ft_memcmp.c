/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:56:30 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/18 10:41:09 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	i = 0;
	tmp_dest = (unsigned char*)dest;
	tmp_src = (unsigned char*)src;
	while (i < n)
	{
		if (tmp_dest[i] != tmp_src[i])
			return (tmp_dest[i] - tmp_src[i]);
		i++;
	}
	return (0);
}

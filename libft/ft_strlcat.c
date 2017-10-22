/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:50:49 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/22 15:27:25 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	de;
	char	*tmp;

	tmp = (char*)src;
	i = 0;
	while (dest[i] && i < size)
		i++;
	de = i;
	while (tmp[i - de] && i < size - 1)
	{
		dest[i] = tmp[i - de];
		i++;
	}
	if (de < size)
		dest[i] = '\0';
	return (de + ft_strlen(tmp));
}

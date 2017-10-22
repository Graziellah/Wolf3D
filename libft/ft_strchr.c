/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:49:06 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/23 09:43:50 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	res = (char*)s;
	i = 0;
	while (res[i])
	{
		if (res[i] == (char)c)
			return (&res[i]);
		i++;
	}
	if (c == 0)
		return (&res[i]);
	return (NULL);
}

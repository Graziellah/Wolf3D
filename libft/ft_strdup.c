/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:42:37 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/18 13:19:38 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		s_src;

	i = 0;
	s_src = 0;
	while (src[s_src])
		s_src++;
	if ((dest = (char*)malloc(sizeof(char) * (s_src + 1))) == NULL)
		return (NULL);
	while (i < s_src)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

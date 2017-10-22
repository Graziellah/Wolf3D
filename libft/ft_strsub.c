/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:07:54 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/23 09:48:45 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	if ((new = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if ((start == 0) && (len == 0))
	{
		new[i] = '\0';
		return (new);
	}
	while (s[start] && (i < len))
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = 0;
	return (new);
}

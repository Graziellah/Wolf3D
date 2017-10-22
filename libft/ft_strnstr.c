/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:43:43 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/21 16:49:35 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_str_cmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while ((s1[i] && s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char			*ft_strnstr(const char *str, const char *lol, size_t n)
{
	size_t		i;

	i = 0;
	if (lol[0] == '\0')
		return ((char*)str);
	if (str[0] == '\0')
		return (NULL);
	while (i < n && str[i])
	{
		if (ft_str_cmp(&str[i], lol, ft_strlen(lol)) == 0 &&
				(ft_strlen(lol) + i <= n))
			return ((char*)&str[i]);
		i++;
	}
	return (NULL);
}

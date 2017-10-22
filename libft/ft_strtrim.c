/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:38:05 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/21 16:42:44 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_space(char const *s, size_t i)
{
	if (!s)
		return (0);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static size_t	ft_find_space_end(char const *s, size_t i)
{
	if (!s)
		return (0);
	while (s[i] == 0 || s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i--;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		len;
	char		*tmp;

	if (!s)
		return (NULL);
	tmp = (char*)s;
	start = ft_find_space(s, 0);
	len = ft_find_space_end(s, ft_strlen((char*)s)) - start + 1;
	if ((tmp = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))) == NULL)
		return (NULL);
	if (start == ft_strlen((char*)s))
	{
		tmp[0] = '\0';
		return (tmp);
	}
	if ((start == 0 && (ft_strlen(tmp) - len) == 0) ||
			(start == (ft_strlen(tmp) + 1)))
		return (tmp);
	return (ft_strsub(*&s, start, len));
}

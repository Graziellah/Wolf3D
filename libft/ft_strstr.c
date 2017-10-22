/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:24:17 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/25 15:48:07 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *str, const char *lol)
{
	int			i;

	i = 0;
	if (lol[0] == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		if (ft_strncmp(&str[i], lol, ft_strlen(lol)) == 0)
			return ((char*)&str[i]);
		i++;
	}
	return (NULL);
}

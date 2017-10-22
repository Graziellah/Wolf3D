/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:19:06 by ghippoda          #+#    #+#             */
/*   Updated: 2017/04/25 14:19:02 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *s1, char const *s2)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if ((new = (char*)malloc(sizeof(char) * (ft_strlen(s1)
		+ ft_strlen(s2)) + 1)) == NULL)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		new[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	new[ft_strlen(s1) + i] = 0;
	free(s1);
	return (new);
}

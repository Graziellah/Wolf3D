/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:40:01 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/21 15:13:54 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	if ((new = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (i < size + 1)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}

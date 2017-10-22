/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:53:30 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/21 15:26:44 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	if (!s)
	{
		ft_putchar(0);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

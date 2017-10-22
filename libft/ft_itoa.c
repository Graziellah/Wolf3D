/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 20:08:49 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/22 11:38:17 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_lenght(int n)
{
	int				ret;

	ret = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		ret++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		ret++;
	}
	return (ret);
}

static void			ft_put_nbr(long n, char *new, size_t i, size_t numbers)
{
	int				neg;

	neg = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
		numbers--;
		new[0] = '-';
	}
	new[i] = '\0';
	i--;
	while (numbers != 0)
	{
		if (n < 10)
			new[i] = n + '0';
		else
		{
			new[i] = (n % 10) + '0';
			n = n / 10;
		}
		numbers--;
		i--;
	}
}

char				*ft_itoa(int n)
{
	char			*new;
	size_t			numbers;
	size_t			i;

	numbers = ft_lenght(n);
	i = numbers;
	if ((new = (char*)malloc(sizeof(*new) * (numbers + 1))) == NULL)
		return (NULL);
	if (n == 0)
	{
		new[0] = '0';
		new[1] = '\0';
	}
	ft_put_nbr((long)n, new, i, numbers);
	return (new);
}

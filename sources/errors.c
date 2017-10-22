/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 17:06:18 by ghippoda          #+#    #+#             */
/*   Updated: 2017/05/16 19:08:54 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	errors(int nb)
{
	if (nb == 1)
		ft_putstr_fd("Not a filename\n", 2);
	if (nb == 2)
		ft_putstr_fd("Error\n", 2);
	if (nb == 3)
		ft_putstr_fd("Malloc error\n", 2);
	exit(0);
}

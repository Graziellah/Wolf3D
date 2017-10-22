/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:38:09 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/21 16:24:55 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*next;

	if (alst == NULL || del == NULL)
		return ;
	node = *alst;
	while (node != NULL)
	{
		next = node->next;
		ft_lstdelone(&node, del);
		node = next;
	}
	*alst = NULL;
}

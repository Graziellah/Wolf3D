/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:38:31 by ghippoda          #+#    #+#             */
/*   Updated: 2016/11/22 13:22:42 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*newlist;
	t_list	*iter;

	if (!lst)
		return (NULL);
	newlist = (*f)(lst);
	iter = newlist;
	lst = lst->next;
	while (lst != NULL)
	{
		iter->next = (*f)(lst);
		iter = iter->next;
		lst = lst->next;
	}
	return (newlist);
}

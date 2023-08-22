/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:33:26 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/28 17:49:03 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*actual;

	newlist = NULL;
	while (lst)
	{
		actual = ft_lstnew(f(lst->content));
		if (!actual)
		{
			ft_lstclear(&actual, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, actual);
		lst = lst->next;
	}
	return (newlist);
}

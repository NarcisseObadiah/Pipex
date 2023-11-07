/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:51:20 by mobadiah          #+#    #+#             */
/*   Updated: 2023/04/08 21:43:14 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;
	t_list	*newnode;

	if (lst == NULL || del == NULL)
		return (NULL);
	temp = lst;
	new_list = NULL;
	while (temp != NULL)
	{
		newnode = malloc(sizeof(t_list));
		if (!newnode)
			return (ft_lstclear(&new_list, del), del(newnode), NULL);
		newnode->content = (*f)(temp->content);
		newnode->next = NULL;
		ft_lstadd_back(&new_list, newnode);
		temp = temp->next;
	}
	return (free(temp), new_list);
}

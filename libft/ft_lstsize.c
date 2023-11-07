/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:25:00 by mobadiah          #+#    #+#             */
/*   Updated: 2023/04/08 17:37:13 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		node_length;
	t_list	*cur_node;

	node_length = 0;
	cur_node = lst;
	while (cur_node != NULL)
	{
		node_length++;
		cur_node = cur_node->next;
	}
	return (node_length);
}

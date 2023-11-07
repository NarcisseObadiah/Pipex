/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:52:20 by mobadiah          #+#    #+#             */
/*   Updated: 2023/04/08 18:55:22 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*pointeur;

	if (s == NULL && !c && !n)
		return (NULL);
	pointeur = (void *)s;
	i = 0;
	while (i < n)
	{
		if (pointeur[i] == (char)c)
			return ((char *)pointeur + i);
		i++;
	}
	return (NULL);
}

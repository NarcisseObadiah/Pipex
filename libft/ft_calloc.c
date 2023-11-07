/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:20:57 by mobadiah          #+#    #+#             */
/*   Updated: 2023/04/08 17:23:28 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointeur;

	pointeur = malloc(count * size);
	if (pointeur == 0)
		return (pointeur);
	ft_bzero(pointeur, count * size);
	return (pointeur);
}

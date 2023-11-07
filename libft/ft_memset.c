/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 05:17:52 by mobadiah          #+#    #+#             */
/*   Updated: 2023/04/08 18:57:05 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// before b = "this is real cool"
// after b = "$$$$$ is cool"

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*pointeur;

	i = 0;
	pointeur = b;
	while (i < len)
		pointeur[i++] = (unsigned char)c;
	return (b);
}

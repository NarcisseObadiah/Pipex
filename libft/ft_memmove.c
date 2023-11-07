/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:40:36 by mobadiah          #+#    #+#             */
/*   Updated: 2023/04/08 19:39:56 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;

	csrc = (char *)src;
	cdst = (char *)dst;
	if (csrc <= cdst)
	{
		csrc += len - 1;
		cdst += len - 1;
		while (len-- && (src != NULL || dst != NULL))
			*cdst-- = *csrc--;
	}
	else
	{
		while (len-- && (src != NULL || dst != NULL))
			*cdst++ = *csrc++;
	}
	return (dst);
}

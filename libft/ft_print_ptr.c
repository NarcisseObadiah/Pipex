/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:40:57 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/08 13:20:10 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_put_ptr(uintptr_t nbr)
{
	if (nbr >= 16)
	{
		ft_put_ptr(nbr / 16);
		ft_put_ptr(nbr % 16);
	}
	else if (nbr <= 9)
		ft_putchar_fd((nbr + '0'), 1);
	else
		ft_putchar_fd((nbr - 10 + 'a'), 1);
}

int	ft_ptr_len(uintptr_t nbr)
{
	int	length;

	length = 0;
	while (nbr != 0)
	{
		length++;
		nbr = nbr / 16;
	}
	return (length);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	if (ptr == 0)
		length += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		length += ft_ptr_len(ptr);
	}
	return (length);
}

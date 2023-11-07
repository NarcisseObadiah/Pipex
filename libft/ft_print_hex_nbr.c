/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:24:13 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/08 13:20:02 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_hex_nbr_len(uintptr_t nbr)
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

void	ft_put_hex_nbr(unsigned int nbr, const char format)
{
	if (nbr >= 16)
	{
		ft_put_hex_nbr((nbr / 16), format);
		ft_put_hex_nbr((nbr % 16), format);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nbr - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((nbr - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex_nbr(unsigned int nbr, const char format)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex_nbr(nbr, format);
	return (ft_hex_nbr_len(nbr));
}

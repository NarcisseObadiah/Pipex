/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:59:53 by mobadiah          #+#    #+#             */
/*   Updated: 2023/04/26 11:37:10 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdlib.h"

int	ft_nbr_len(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*string;
	int		len;

	len = ft_nbr_len(n);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (NULL);
	string[len] = '\0';
	while (n != 0)
	{
		string[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (string);
}	

int	ft_print_unsigned(unsigned int n)
{
	char	*nbr;
	int		length;

	length = 0;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		nbr = ft_uitoa(n);
		length += ft_printstr(nbr);
		free(nbr);
	}
	return (length);
}

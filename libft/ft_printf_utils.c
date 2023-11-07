/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:52:52 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/08 13:09:11 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "stdlib.h"

void	ft_putstr(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		write(1, &string[i], 1);
		i++;
	}
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_printstr(char *string)
{
	int	len;

	len = 0;
	if (string == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (string[len] != '\0')
	{
		write(1, &string[len], 1);
		len++;
	}
	return (len);
}

int	ft_print_nbr(int n)
{
	int		len;
	char	*string;

	len = 0;
	string = ft_itoa(n);
	len = ft_printstr(string);
	free(string);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:48:23 by mobadiah          #+#    #+#             */
/*   Updated: 2023/04/26 17:24:59 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdlib.h"
#include "stdarg.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format_check(va_list args, const char format)
{	
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		length += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		length += ft_print_hex_nbr(va_arg(args, unsigned int), format);
	else if (format == '%')
		length += ft_printpercent();
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		length;
	va_list	args;

	length = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			length += ft_format_check(args, *(str + 1));
				str++;
		}
		else
			length += ft_printchar(*str);
		str++;
	}
	va_end(args);
	return (length);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 03:30:41 by mobadiah          #+#    #+#             */
/*   Updated: 2023/04/26 11:25:15 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_print_hex_nbr(unsigned int nbr, const char format);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_unsigned(unsigned int n);
int		ft_format_check(va_list args, const char format);
int		ft_printchar(int c);
int		ft_print_nbr(int n);
int		ft_printpercent(void);
void	ft_putstr(char *string);
void	ft_put_ptr(uintptr_t nbr);

int		ft_printstr(char *string);
int		ft_hex_nbr_len(uintptr_t nbr);
void	ft_put_hex_nbr(unsigned int nbr, const char format);
#endif
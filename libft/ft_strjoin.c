/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:26:02 by mobadiah          #+#    #+#             */
/*   Updated: 2023/04/08 19:00:47 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str_len;
	char	*string;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = malloc(sizeof(char) * (str_len));
	if (!string)
		return (NULL);
	ft_memmove(string, s1, ft_strlen(s1));
	ft_memmove((string + ft_strlen(s1)), s2, ft_strlen(s2));
	string[str_len - 1] = '\0';
	return (string);
}

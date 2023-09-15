/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 08:55:08 by mobadiah          #+#    #+#             */
/*   Updated: 2023/04/08 19:00:20 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimed_str;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	trimed_str = (char *)malloc(sizeof(char) * ((end - start + 1) + 1));
	if (!trimed_str)
		return (NULL);
	ft_memmove(trimed_str, s1 + start, end - start + 1);
	trimed_str[end - start + 1] = '\0';
	return (trimed_str);
}

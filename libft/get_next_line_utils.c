/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:59:19 by mobadiah          #+#    #+#             */
/*   Updated: 2023/08/12 02:20:17 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	len;
	size_t	src_len;

	len = 0;
	src_len = gnl_strlen(src);
	if (dstsize > 0)
	{
		while (len < dstsize - 1 && len < src_len)
		{
			dst[len] = src[len];
			len++;
		}
		dst[len] = '\0';
	}
	return (src_len);
}

char	*gnl_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2, int read_size)
{
	int		s1_len;
	int		i;
	char	*final_string;

	i = 0;
	s1_len = gnl_strlen(s1);
	final_string = (char *) malloc(s1_len + read_size + 1);
	if (!final_string)
		return (free(final_string), NULL);
	gnl_strlcpy(final_string, s1, s1_len + 1);
	while (i < read_size)
	{
		final_string[s1_len + i] = s2[i];
		i++;
	}
	final_string[s1_len + i] = '\0';
	return (free(s1), s1 = NULL, final_string);
}

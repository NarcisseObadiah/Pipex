/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 03:11:00 by mobadiah          #+#    #+#             */
/*   Updated: 2023/04/08 19:02:50 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	word_count;
	int	i;

	i = 0;
	word_count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			word_count++;
		i++;
	}
	return (word_count);
}

static int	ft_word_size(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strings, int word)
{
	while (word-- > 0)
		free(strings[word]);
	free(strings);
}

char	**ft_split(char const *s, char c)
{
	int		word_char_position;
	int		number_of_word;
	int		word_size;
	int		word;
	char	**strings;

	word_char_position = 0;
	word = -1;
	number_of_word = ft_count_word(s, c);
	strings = (char **)malloc((number_of_word + 1) * sizeof(char *));
	if (!(strings))
		return (NULL);
	while (++word < number_of_word)
	{
		while (s[word_char_position] == c)
			word_char_position++;
		word_size = ft_word_size(s, c, word_char_position);
		strings[word] = ft_substr(s, word_char_position, word_size);
		if (!(strings[word]))
			return (ft_free(strings, word), NULL);
		word_char_position += word_size;
	}
	strings[word] = 0;
	return (strings);
}

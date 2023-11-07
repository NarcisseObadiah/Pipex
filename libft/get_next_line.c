/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:56:21 by mobadiah          #+#    #+#             */
/*   Updated: 2023/08/12 02:20:17 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_read_file(int fd, char *stash)
{
	int		read_size;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(buffer), NULL);
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size == -1)
		return (free(buffer), free(stash), NULL);
	while (read_size > 0)
	{
		stash = gnl_strjoin(stash, buffer, read_size);
		if (stash && gnl_strchr(stash, '\n'))
			break ;
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (free(buffer), buffer = NULL, free(stash), NULL);
		if (read_size == 0)
			return (free(buffer), buffer = NULL, stash);
	}
	free(buffer);
	buffer = NULL;
	return (stash);
}

static char	*gnl_extract_line(char *stash)
{
	char	*line;
	int		len;

	if (!stash)
		return (NULL);
	len = 0;
	while (stash[len] != '\0' && stash[len] != '\n')
		len++;
	if (stash[len] != '\n')
	{
		line = (char *) malloc(sizeof(char) * (len + 1));
		if (!line)
			return (NULL);
		gnl_strlcpy(line, stash, len + 1);
	}
	else
	{
		line = (char *) malloc(sizeof(char) * (len + 2));
		if (!line)
			return (NULL);
		gnl_strlcpy(line, stash, len + 2);
	}
	return (line);
}

static char	*gnl_adjust_stash(char *stash, int line_len)
{
	char	*new_stash;
	int		r_len;

	new_stash = (char *)malloc((gnl_strlen(stash) - line_len + 1));
	if (!new_stash)
		return (free(stash), free(new_stash), NULL);
	r_len = 0;
	while (stash[line_len + r_len])
	{
		new_stash[r_len] = stash[line_len + r_len];
		r_len++;
	}
	new_stash[r_len] = '\0';
	if (new_stash[0] == 0)
		return (free(stash), free(new_stash), NULL);
	return (free(stash), new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), stash = NULL, NULL);
	stash = gnl_read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = gnl_extract_line(stash);
	stash = gnl_adjust_stash(stash, gnl_strlen(line));
	return (line);
}

// int main()
// {
//     int fd = open("descriptor.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         printf("Erreur lors de l'ouverture du fichier.\n");
//         return 1;
//     }

//     char *line;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s\n", line);
//         free(line);
//     }

//     close(fd);
//     return 0;
// }

// int main(void)
// {
//     char *line;

//     printf("Enter text (press Ctrl+D to stop):\n");
//     while ((line = get_next_line(0)) != NULL) {
//         printf("Read line: %s\n", line);
//         free(line);
//     }
//     return 0;
// }

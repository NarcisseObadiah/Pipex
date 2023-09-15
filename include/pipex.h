/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:12:58 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/15 15:40:29 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "error.h"

void	ft_error(void);
char	**ft_get_path(char **envp);
char	*ft_get_cmd_path(char **envp, char *cmd_sect);
void	free_path_sections(char **path_sections);

#endif
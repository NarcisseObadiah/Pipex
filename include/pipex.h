/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narcisse <narcisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:12:58 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/16 02:51:23 by narcisse         ###   ########.fr       */
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
void    ft_exec_command(char **envp, char *cmd);

#endif
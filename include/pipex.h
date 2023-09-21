/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:12:58 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/20 15:54:43 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define E_ARG "Wrong number of arguments or environ variables are empty.\n"
# define E_PIPE "Pipe error occurred.\n"
# define E_FORK "Fork could not create a child process.\n"
# define E_OPENO "Can't open the outfile.\n"
# define E_OPENI "Can't open the infile.\n"
# define E_EXECVE "Execve failed.\n"
# define E_CMD "Command not found.\n"
# define E_ENVP "Error occurred while duplicating environ variable PATH.\n"
# define E_ENVPATH "Can't find environ variable PATH.\n"

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

void	ft_error(char *std, char *msg);
char	**ft_get_path(char **envp);
char	*ft_get_cmd_path(char **envp, char *cmd_sect);
void	free_path_sections(char **path_sections);
void	ft_exec_command(char **envp, char *cmd);
void	ft_close_all_fd(int *fd);

#endif
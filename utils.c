/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narcisse <narcisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:52:54 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/16 02:49:31 by narcisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	ft_error(void)
{
	perror("Error!!!");
	exit(EXIT_FAILURE);
}

//Function to free each section inside the array of path_sections, 
//then free the array itself

void	free_path_sections(char **path_sections)
{
	int	i;

	i = 0;
	if (path_sections)
	{
		while (path_sections[i] != NULL)
		{
			free(path_sections[i]);
			i++;
		}
		free(path_sections);
	}
}

/* function extracts and splits the PATH environment variable into 
an array of path sections. */


char	**ft_get_path(char **envp)
{
	char	*envp_path;
	char	**path_sections;
	int		i;

	envp_path = NULL;
	path_sections = NULL;
	i = 0;
	while (envp[i++])
	{
		if (ft_strncmp(envp[i], "PATH", 4))
		{
			envp_path = ft_strdup(envp[i]);
			if (!envp_path)
				ft_error();
			break ;
		}
	}
	if (envp_path)
	{
		path_sections = ft_split(envp_path, ":");
		free(envp_path);
	}
	return (path_sections);
}
/*access checks every path in env_path if we get access permission.
Upon successful completion, the value 0 is returned; 
otherwise the value -1 is returned and the global variable 
errno is set to indicate the error.*/

char	*ft_get_cmd_path(char **envp, char *cmd_sect)
{
	char	**path_sections;
	char	*right_path;
	char	*cmd;
	int		i;

	if (access(cmd_sect, F_OK | X_OK) == 0)
		return (ft_strdup(cmd_sect));
	cmd = ft_strjoin("/", cmd_sect);
	path_sections = ft_get_path(envp);
	i = 0;
	while (path_sections[i++])
	{
		right_path = ft_strjoin(path_sections[i], cmd);
		if (access(right_path, F_OK | X_OK) == 0)
			break ;
		free(right_path);
		right_path = NULL;
	}
	free_path_sections(path_sections);
	free(cmd);
	return (right_path);
}

// char *cmd = "ls -l -a" && cmd2 = "wc -l" 
// 		        [0  1  3]

void ft_exec_command(char **envp, char *cmd)
{
	char *path;
	char **cmd_sections;

	path = NUll;
	cmd_sections = ft_split(cmd, ' ');
	path = ft_get_cmd_path(envp, cmd_sections[0]);
	if (!path || !cmd_sections)
			free_path_sections(cmd_sections);
	execve(path, cmd_sections, envp);
	ft_error();
}


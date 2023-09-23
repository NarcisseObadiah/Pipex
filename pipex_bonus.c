/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:37:11 by narcisse          #+#    #+#             */
/*   Updated: 2023/09/23 20:55:40 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

void	ft_child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error("Pipe error!!");
	pid = fork();
	if (pid == -1)
		error("Process forking error");
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_exec_command(envp, argv);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	ft_here_doc(char *limiter, int argc)
{
	pid_t	pid2;
	int		fd[2];
	char	*line;

	if (argc < 6)
		error("Wrong number of arguments");
	if (pipe(fd) == -1)
		error("Pipe Error");
	pid2 = fork();
	if (pid2 == 0)
	{
		close (fd[0]);
		line = get_next_line(0);
		while (line != NULL) // Read lines from stdin
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			ft_putstr_fd(line, fd[1]);
			line = get_next_line(0);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid2, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc < 5)
		error("Wrong arguments!!!\n");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		ft_here_doc(argv[2], argc);
	}
	else
	{
		i = 2;
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		infile = open(argv[1], O_RDONLY);
		dup2(infile, STDIN_FILENO);
	}
	while (i < argc - 2)
		ft_child_process(argv[i++], envp);
	dup2(outfile, STDOUT_FILENO);
	ft_exec_command(envp, argv[argc - 2]);
	printf("main process on going!!!");
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:02:19 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/17 17:10:43 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h" 

//Child1 process redirect the infile in read mode and redirect the stdin  to it.
/*then redirect the write end of the pipe (fd[1])*/

void	ft_child1_process(char **argv, char **envp, int *fd)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY, 0777);
	if (file1 == -1)
		ft_error(E_OPENI, "Errno");
	dup2(fd[1], STDOUT_FILENO);
	dup2(file1, STDIN_FILENO);
	close(file1);
	close(fd[0]);
	close(fd[1]);
	ft_exec_command(envp, argv[2]);
}

//Child2 process redirect the outfile in write mode and
/* redirect the stdin in fd[0], and the stdout to the outfile*/

void	ft_child2_process(char **argv, char **envp, int *fd)
{
	int	file2;

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file2 == -1)
		ft_error(E_OPENO, "Errno");
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(file2);
	close(fd[0]);
	close(fd[1]);
	ft_exec_command(envp, argv[3]);
}
/*
the usage of fork, pipe, and wait in a Unix-like environment 
to create a parent-child process hierarchy for concurrent execution.
It involves the following steps:

1** pipe(fd) creates a pipe with two file descriptors:
	 fd[0] for reading and fd[1] for writing.
2** pid = fork() creates a child process. 
	If pid is 0, it's the child process.
3** The workload is divided between two child processes,
	while the parent process waits for them to finish.
4** wait() suspends the parent process until information about 
	the termination of a child process is available.
	This structure allows for concurrent execution and efficient
	resource sharing between parent and 
child processes in a piped communication setup.*/

/*
	Unix-Like Environment
		|
		fork()              Parent Process
	/     \                 |
	Child   Child          Concurrent Execution
	|       |                   |
	pipe(fd)  Workload          wait()
	|       |                   |
	fd[0]   fd[1]             Child Process
	Read    Write              Termination Info

*/

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error(E_PIPE, "Errno");
		pid = fork();
		if (pid == -1)
			ft_error(E_FORK, "Errno");
		else if (pid == 0)
			ft_child1_process(argv, envp, fd);
		else
		{
			waitpid(pid, NULL, 0);
			ft_child2_process(argv, envp, fd);
		}
		close(fd[0]);
		close(fd[1]);
	}
	else
	{
		ft_putstr_fd("Error: Wrong arguments!!!\n", 2);
		ft_putstr_fd("Eg: ./Pipex <file1> <cmd1> <cmd2> <file2>\n ", 2);
	}
	system("leaks pipex");
}

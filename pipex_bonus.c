/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narcisse <narcisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:37:11 by narcisse          #+#    #+#             */
/*   Updated: 2023/09/22 14:48:21 by narcisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

void ft_child_process(char *argv, char **envp)
{
    pid_t pid;
    int   fd[2];

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

void ft_here_doc(char *limiter, int argc)
{
    pid_t pid2;
    int fd[2];
    char *line;

    if (argc < 6)
        error("Wrong number of arguments");
    if (pipe(fd) == -1)
        error("Pipe Error");
    pid2 = fork();
    if (pid2 == 0) // Child process
    {
        close(fd[0]); // Close read end of the pipe
        while ((line = get_next_line(0)) != NULL) // Read lines from stdin
        {
            if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0) // Compare with LIMITER
                exit(EXIT_SUCCESS);
            ft_putstr_fd(line, fd[1]);
        }
    }
    else // Parent process
    {
        close(fd[1]); // Close write end of the pipe in the parent
        dup2(fd[0], STDIN_FILENO); // Redirect stdin to read from the pipe
        ft_close_all_fd(fd);
        waitpid(pid2, NULL, 0); // Wait for the child process to finish
    }
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc >= 5)
	{
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
        ft_putstr("main process on going!!!");
		ft_exec_command(envp, argv[argc - 2]);
	}
	error("Wrong arguments!!!\n");
}
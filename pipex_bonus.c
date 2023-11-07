/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 02:25:40 by mobadiah          #+#    #+#             */
/*   Updated: 2023/11/07 06:19:42 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"


int	l_get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_putstr("pipe error");
	pid = fork();
	if (pid == -1)
		ft_putstr("process error");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_exec_command(envp, argv);
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
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc < 6)
		ft_putstr("Wrong number of argument!!!");
	if (pipe(fd) == -1)
		ft_putstr("pipe error");
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (l_get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	input_file;
	int	output_file;

	if (argc >= 5)
	{
		if	(ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
		{
			i = 3;
			output_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
			if (output_file == -1)
				ft_putstr("file error");
			ft_here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			output_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			input_file = open(argv[2], O_RDONLY);
			// if (output_file == -1 || input_file == -1)
			// 	ft_putstr("file error");
			dup2(input_file, STDIN_FILENO);
		}
		while (i < argc - 2)
			child_process(argv[i++], envp);
		dup2(output_file, STDOUT_FILENO);
		ft_exec_command(envp, argv[argc - 2]);
	}
}

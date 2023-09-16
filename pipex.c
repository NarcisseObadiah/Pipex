/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narcisse <narcisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:02:19 by mobadiah          #+#    #+#             */
/*   Updated: 2023/09/16 04:19:39 by narcisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h" 

//Child1 processs

void ft_child1_process(char **argv, char **envp,  int *fd)
{
    int file1;

    file1 = open(argv[1], O_RDONLY, 0777);
    if (file1 == -1)
        ft_error();
    dup2(fd[1], STDOUT_FILENO);
    dup2(file1, STDIN_FILENO);
    close(file1);
    close(file1)
    ft_exec_command(argv[1], envp);
}
 
//Child2 process

void ft_child2_process(char **argv, char **envp,  int *fd)
 {
    int file2;
    file2 = open(argv[1], O_RDONLY | O_CREA | O_TRUNC, 0777);
    if (file2 == -1)
        ft_error();
    dup2(fd[0], STDOUT_FILENO);
    dup2(file2, STDIN_FILENO);
    close(file2);
    close(fd[1]);
    ft_exec_command(argv[4], envp);
 }


 int main(int argc, char **argv, char **envp,)
 {
    int fd[2];
    pid_t pid;

    if (argc == 5)
    {
        if (pipe(fd) == -1)
            ft_error();
        pid = fork();
        if (pid == -1)
            ft_error();
        if(pid == 0)
            ft_child1_process(argv, envp, fd);
        waitpid(pid, NULL, 0);
        ft_child2_process(argv, envp, fd);
    }
    else
    {
        ft_putstr_fd("Error: Wrong arguments!!!", 2);
        ft_putstr_fd("Eg: ./Pipex <file1> <cmd1> <cmd2> <file2>\n ", 2);
    }
    
 }
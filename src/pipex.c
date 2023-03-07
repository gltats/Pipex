/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:03:42 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/07 18:04:43 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
//PID -> process identifier, is a unique numerical value assigned by an 
//operating system to each process that is created on a computer
//waitpid -> is used by a parent process to wait for the termination 
//of one of its child processes.
/* Child process that run inside a fork, take the filein, put the output inside
 a pipe, closes the read side and executes  */
static void	child_process(t_pipex pipex, char **argv, char *envp)
{
	dup2(pipex.pipe[1], 1);
	dup2(pipex.infile, 0);
	close(pipex.pipe[0]);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		msg(ERROR_COMMAND_NOT_FOUND);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, &envp);
}

/* Parent process that take the data from the pipe, change the output for the
 fileout, closes the write side and executes */
static void	parent_process(t_pipex pipex, char **argv, char *envp)
{
	dup2(pipex.pipe[0], 0);
	dup2(pipex.outfile, 1);
	close(pipex.pipe[1]);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		msg(ERROR_COMMAND_NOT_FOUND);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, &envp);
}

/* Pipex function  opens input and output files, 
sets up a pipe, forks two child processes, 
and executes the child and parent processes according */
int	pipex(int argc, char **argv, char *envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (msg(ERROR_INPUT));
	else if(argc == 5)
	{
		pipex.infile = open(argv[1], O_RDONLY, 0777);
		pipex.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (pipex.infile == -1 || pipex.outfile == -1)
			msg_error(ERROR_OUTFILE);
		if (pipe(pipex.pipe) == -1)
			msg_error(ERROR_PIPE);
		pipex.paths = find_path(envp);
		pipex.cmd_paths = ft_split(pipex.paths, ':');
		pipex.pid1 = fork();
		if (pipex.pid1 == -1)
			msg_error(ERROR_FORK);
		if (pipex.pid1 == 0)
			child_process(pipex, argv, envp);
		pipex.pid2 = fork();
		if (pipex.pid2 == 0)
			parent_process(pipex, argv, envp);
		close_pipes(&pipex);
		waitpid(pipex.pid1, NULL, 0);
		waitpid(pipex.pid2, NULL, 0);
		parent_free(&pipex);
		}
	return (0);
}

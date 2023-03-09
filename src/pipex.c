/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:03:42 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/09 17:32:30 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
//PID -> process identifier, is a unique numerical value assigned by an 
//operating system to each process that is created on a computer
//waitpid -> is used by a parent process to wait for the termination 
//of one of its child processes.
/* Child process that run inside a fork, take the filein, put the output inside
 a pipe, closes the read side and executes  */
static void	child_process(t_pipex pipex, char **argv, char **envp)
{
	if ((dup2(pipex.pipe[1], STDOUT_FILENO)) < 0)
			perror("Error dup2: ");
		dup2(pipex.infile, STDIN_FILENO);
		close_pipes(&pipex);
		close(pipex.infile);
		close(pipex.outfile);
		parse_args(&pipex, argv[2]);
		check_for_path(&pipex, 0);
		if (!pipex.cmd)
		{
			if (!ft_strchr(pipex.cmd_args[0], '/'))
				msg(ERROR_COMMAND_NOT_FOUND, 0);
			free_cmd(&pipex);
			parent_free(&pipex);
			exit (CMD_NOT_FOUND);
		}
		if ((execve(pipex.cmd, pipex.cmd_args, envp)) < 0)
		{
			free_cmd(&pipex);
			parent_free(&pipex);
			msg_error(ERROR_EXECVE);
		}
}

/* Parent process that take the pipex from the pipe, change the output for the
 fileout, closes the write side and executes */
static void	parent_process(t_pipex pipex, char **argv, char **envp)
{
	if ((dup2(pipex.pipe[0], STDIN_FILENO)) < 0)
		perror("Error dup2: ");
	dup2(pipex.outfile, STDOUT_FILENO);
	close_pipes(&pipex);
	close(pipex.outfile);
	close(pipex.infile);
	parse_args(&pipex, argv[3]);
	check_for_path(&pipex, 1);
	if (!pipex.cmd)
	{
		if (!ft_strchr(pipex.cmd_args[0], '/'))
			msg(ERROR_COMMAND_NOT_FOUND, 0);
		free_cmd(&pipex);
		parent_free(&pipex);
		exit (CMD_NOT_FOUND);
	}
	if ((execve(pipex.cmd, pipex.cmd_args, envp)) < 0)
	{
		free_cmd(&pipex);
		parent_free(&pipex);
		msg_error(ERROR_EXECVE);
	}
}

static int	ft_init(t_pipex *pipex, char **argv, char **envp)
{
	int	status;

	status = 0;
	ft_infile(argv, pipex);
	status = ft_outfile(argv, pipex);
	pipex->paths = find_path(*envp);
	pipex->cmd_paths = ft_split(pipex->paths, ':');
	return (status);
}

/* Pipex function  opens input and output files, 
sets up a pipe, forks two child processes, 
and executes the child and parent processes according */
int	pipex(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int status;
	
	status = 0;
	if (argc != 5)
		return (msg(ERROR_INPUT, 1));
	else if(argc == 5)
	{
		status = ft_init(&pipex, argv, envp);
		if (pipe(pipex.pipe) == -1)
			msg_error(ERROR_PIPE);
		pipex.pid[0] = fork();
		if (pipex.pid[0] == 0)
			child_process(pipex, argv, envp);
		pipex.pid[1] = fork();
		if (pipex.pid[1] == 0)
			parent_process(pipex, argv, envp);
		close_pipes(&pipex);
		close(pipex.infile);
		close(pipex.outfile);
		waitpid(pipex.pid[0], NULL, 0);
		waitpid(pipex.pid[1], &pipex.exit_status, 0);
		parent_free(&pipex);
		if (status == 1)
			return (1);
		}
	return (WEXITSTATUS(pipex.exit_status));
}

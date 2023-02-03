/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:03:42 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/03 19:40:17 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//PID -> process identifier, is a unique numerical value assigned by an 
//operating system to each process that is created on a computer
//waitpid -> is used by a parent process to wait for the termination 
//of one of its child processes.
/* Child process that run inside a fork, take the filein, put the output inside
 a pipe, closes the read side and executes  */
static void child_process(char **argv, char **envp, int *fd)
{
	int infile;

	infile = open(argv[1], O_RDONLY);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], **envp);
	
}

/* Parent process that take the data from the pipe, change the output for the
 fileout, closes the write side and executes */
static void parent_process(char **argv, char **envp, int *fd)
{
	int outfile;
	
	outfile = open(fd[4], O_WRONLY);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], *envp);
}

/* Pipex function runs the child and parent process or displays an error
 message if needed */
int pipex(int argc, char **argv, char **envp)
{
	int	fd[2];
	pid_t pid1;
	int ret;
	int status;
	
	if (argc != 5)
		return(ERROR_INVALID_ARG);
	if (pipe(fd) == -1)
		return(ERROR);
		
	pid1 = fork();
    if (pid1 == -1) 
		return(ERROR);
	if (pid1 == 0) 
	{
		child_process(argv, envp, fd);
		printf("I am the child process, my PID is %d\n", getpid());
		return(0);
	}
	else
	{
		ret = waitpid(pid1, &status, 0);
		if (ret == -1) 
			return(ERROR);
		parent_process(argv, envp, fd);
		printf("I am the parent process, my child PID is %d\n", pid1);
		printf("My first child exit status is %d\n", status);
	}
	return(0);
}

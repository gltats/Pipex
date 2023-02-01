/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:03:42 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/01 17:27:03 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//PID -> process identifier, is a unique numerical value assigned by an 
//operating system to each process that is created on a computer
//waitpid -> is used by a parent process to wait for the termination 
//of one of its child processes.
int pipex(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	pid_t pid1;
	pid_t pid2;
	int ret;
	int status;
	
	if (argc != 5)
	{
		printf("Error: incorrect number of arguments\n");
		return (1);
	}
	if (pipe(fd) == -1)
	{
		perror("ERROR");
		return (1);
	}
		
	pid1 = fork();
    if (pid1 == -1) 
	{
		perror("ERROR");
		return (1);
	}
	if (pid1 == 0) 
	{
		printf("I am the child process, my PID is %d\n", getpid());
		return(0);
	}
	else
	{
		ret = waitpid(pid1, &status, 0);
		if (ret == -1) 
		{
			perror("waitpid");
			return (1);
		}
		printf("I am the parent process, my first child's PID is %d\n", pid1);
		printf("My first child exit status is %d\n", status);
	}
	
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("ERROR");
		return (1);
	}
	if (pid2 == 0) 
	{
		printf("I am the child process, my PID is %d\n", getpid());
		return(0);
	}
	else 
	{
		ret = waitpid(pid2, &status, 0);
		if (ret == -1) 
		{
			perror("waitpid");
			return(1);
		}
		printf("I am the parent process, my second child's PID is %d\n", pid2);
		printf("My second child exit status is %d\n", status);
	}
	close(fd[0]);
	close(fd[1]);
	return(0);
}

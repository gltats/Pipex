/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:06:28 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/09 17:33:27 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"

//\033[31m -> sets the color to red
//\e[0m -> restes the color
# define ERROR "\033[91mERROR\e[0m"
# define ERROR_COMMAND_NOT_FOUND "\033[91m Error: \e[0m \033[31m Command not found\n \e[0m"
# define ERROR_EXECVE "\033[91m Error:\e[0m \033[31mExeceve\n\e[0m"
# define ERROR_NO_TOKENS "\033[91mError:\e[0m \033[31mNo path\n\e[0m"
# define ERROR_INFILE "\033[91mError:\e[0m \033[31mInfile\n\e[0m"
# define ERROR_OUTFILE "\033[91mError:\e[0m \033[31mOutfile\n\e[0m"
# define ERROR_INPUT "\033[91mError:\e[0m \033[31m Invalid number of arguments.\n\e[0m"
# define ERROR_PIPE "\033[91mError:\e[0m \033[31mPipe\n\e[0m"
# define ERROR_FORK "\033[91mError:\e[0m \033[31mFork\n\e[0m"
# define FILE_NOT_FOUND "\033[91m Error: \e[0m \033[31m Directory or file not found\n \e[0m"

# define CMD_NOT_FOUND 127
# define ERR_FILE 1

typedef struct s_pipex
{
	pid_t	pid[2];
	int		pipe[2];
	int		infile;
	int		outfile;
	int		exit_status;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

//utils.c
void	close_pipes(t_pipex *pipex);
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);
int		msg(char *err, int err_exit);
void	msg_error(char *err);
//parsing.c
void	parse_args(t_pipex *pipex, char *args);
//execute.c
char	*find_path(char *envp);
char	*get_cmd(char **path, char *cmd);
void	free_cmd(t_pipex *pipex);
void	check_for_path(t_pipex *pipex, int i);
//files.c
void ft_infile(char **argv, t_pipex *pipex);
int ft_outfile(char **argv, t_pipex *pipex);
//pipex.c
int	pipex(int argc, char **argv, char **envp);
//main.c
int	main(int argc, char **argv, char **envp);
#endif
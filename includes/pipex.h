/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:06:28 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/07 16:31:46 by tgomes-l         ###   ########.fr       */
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
# include "../libft/libft.h"

//\033[31m -> sets the color to red
//\e[0m -> restes the color
# define ERROR "\033[31mERROR\e[0m"
# define ERROR_COMMAND_NOT_FOUND "\033[31mError:Command not found\n\e[0m"
# define ERROR_EXECVE "\033[31mExecve error:\n\e[0m"
# define ERROR_NO_TOKENS "\033[31mError: No path\n\e[0m"
# define ERROR_INFILE "\033[31mInfile\n\e[0m"
# define ERROR_OUTFILE "\033[31mOutfile\n\e[0m"
# define ERROR_INPUT "\033[31mInvalid number of arguments.\n\e[0m"
# define ERROR_PIPE "\033[31mPipe\n\e[0m"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

char	*get_cmd(char **path, char *cmd);
char	*find_path(char *envp);
int		pipex(int argc, char **argv, char *envp);
int		main(int argc, char *argv[], char *envp[]);
void	close_pipes(t_pipex *pipex);
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);
int		msg(char *err);
void	msg_error(char *err);

#endif
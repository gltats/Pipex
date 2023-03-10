/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:43:09 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/10 16:15:17 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
/*takes an environment variable PATH as an argument, 
searches for the PATH= prefix, 
and returns a pointer to the start of the actual path string.*/
char	*find_path(char *envp)
{
	while (ft_strncmp("PATH=", envp, 5))
		envp++;
	return (envp + 5);
}

/*takes a list of directories in which to search for a command, 
and a command name, and constructs the full path to the command 
if it exists in one of the directories. 
It returns a pointer to the full path if found, 
or 0 if the command is not found*/
char	*get_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		path++;
	}
	return (0);
}

/*frees the memory allocated to the cmd_args and cmd fields*/
void	free_cmd(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

/*checks if the first argument in cmd_args contains a slash), 
and sets the cmd field accordingly. 
If the command does not contain a slash, get_cmd is called to search 
for the command in the directories listed in cmd_paths. 
If the command is not found, an error message is printed with ms*/
void	check_for_path(t_pipex *pipex, int i)
{
	if (ft_strchr(pipex->cmd_args[0], '/') != 0)
	{
		if (access(pipex->cmd_args[0], F_OK) == 0)
			pipex->cmd = pipex->cmd_args[0];
		else
		{
			if (i != 0)
				msg(pipex->cmd_args[0], ERROR_FILE, 127);
			else
				msg(pipex->cmd_args[0], ERROR_FILE, 3);
		}
	}
	if (ft_strchr(pipex->cmd_args[0], '/') == 0)
		pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0]);
}

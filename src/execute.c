/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:43:09 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/09 17:17:16 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char *envp)
{
	while (ft_strncmp("PATH=", envp, 5))
		envp++;
	return (envp);
}

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

void	check_for_path(t_pipex *pipex, int i)
{
	if (ft_strchr(pipex->cmd_args[0], '/') != 0)
	{
		if (access(pipex->cmd_args[0], F_OK) == 0)
			pipex->cmd = pipex->cmd_args[0];
		else
		{
			if (i != 0)
				msg(FILE_NOT_FOUND, 127);
			else
				msg(FILE_NOT_FOUND, 3);
		}
	}
	if (ft_strchr(pipex->cmd_args[0], '/') == 0)
		pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0]);
}

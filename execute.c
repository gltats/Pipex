/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:43:09 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/10 21:47:01 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char *envp)
{
	while (ft_strncmp("PATH=", envp, 5))
		envp++;
	return (envp);
}

// static char	*get_cmd(char **path, char *cmd)
// {
// 	char	*tmp;
// 	char	*command;

// 	while (*path)
// 	{
// 		tmp = ft_strjoin(*path, "/");
// 		command = ft_strjoin(tmp, cmd);
// 		free(tmp);
// 		if (access(command, 0) == 0)
// 			return (command);
// 		free(command);
// 		path++;
// 	}
// 	return (0);
// }

int execute(char *envp, char *argv)
{
	char **token;
	char *second_path;
	char *tmp_path;
	int i;

	token = ft_split(find_path(envp), ':'); //need the path splitted from :
	if (token == NULL)
		return (ERROR_NO_TOKENS);
	i = 0;
	while (token[i])
	{
		tmp_path = ft_strjoin(token[i], "/");
		second_path = ft_strjoin(tmp_path, &argv[0]);
		free(tmp_path);
		if (access(second_path, R_OK) == 0)// checking the access
		{
			if (execve(second_path, &argv, &envp) == -1)// checking the execution of the program that is referred to by pathname
			{
				free(second_path);
				return (ERROR_EXECVE);
			}
		}
		free(second_path);
		i++;
	}
	return (ERROR_COMMAND_NOT_FOUND);
}
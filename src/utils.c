/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:43 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/09 19:05:20 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_pipes(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}

void	child_free(t_pipex *pipex)
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

// int	msg(char *err, int err_exit)
// {
// 	ft_putstr(err);
// 	if (err_exit == 1)
// 		exit(err_exit);
// 	if (err_exit == 127)
// 		exit(err_exit);
// 	if (err_exit == 3)
// 		err_exit++;
// 	return (1);
// }

void	msg(char *f, char *s, int err_exit)
{
	char escape_sequence[32];
	size_t escape_sequence_len = sizeof(escape_sequence);
	
	strlcpy(escape_sequence, "\033[91m", escape_sequence_len);
	strlcat(escape_sequence, s, escape_sequence_len);
	strlcat(escape_sequence, "\e[0m", escape_sequence_len);
	ft_putstr_fd(escape_sequence, 2);
	ft_putstr_fd("\033[91m: \e[0m", 2);
	strlcpy(escape_sequence, "\033[91m", escape_sequence_len);
	strlcat(escape_sequence, f, escape_sequence_len);
	strlcat(escape_sequence, "\e[0m", escape_sequence_len);
	ft_putstr_fd(escape_sequence, 2);
	ft_putstr_fd("\n", 2);
	if (err_exit == 1)
		exit(err_exit);
	if (err_exit == 127)
		exit(err_exit);
	if (err_exit == 3)
		err_exit++;
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

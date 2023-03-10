/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:43 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/10 16:16:30 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*function closes the read and write ends of the pipe */
void	close_pipes(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

/*closes the file descriptors for input and output files
and frees the memory allocated for the paths to the executable commands*/
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

/* frees the memory allocated for the command arguments and the command itself*/
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

/*function prints an error message to stderr 
If err_exit is set to 1, the function will
 exit with an error status. 
If err_exit is set to 127, the function will 
 exit with the command not found error status. 
If err_exit is set to 3, it is incremented by 1.*/
void	msg(char *f, char *s, int err_exit)
{
	char	escape_sequence[32];
	size_t	escape_sequence_len;

	escape_sequence_len = sizeof(escape_sequence);
	ft_strlcpy(escape_sequence, "\033[91m", escape_sequence_len);
	ft_strlcat(escape_sequence, s, escape_sequence_len);
	ft_strlcat(escape_sequence, "\e[0m", escape_sequence_len);
	ft_putstr_fd(escape_sequence, 2);
	ft_putstr_fd("\033[91m: \e[0m", 2);
	ft_strlcpy(escape_sequence, "\033[91m", escape_sequence_len);
	ft_strlcat(escape_sequence, f, escape_sequence_len);
	ft_strlcat(escape_sequence, "\e[0m", escape_sequence_len);
	ft_putstr_fd(escape_sequence, 2);
	ft_putstr_fd("\n", 2);
	if (err_exit == 1)
		exit(err_exit);
	if (err_exit == 127)
		exit(err_exit);
	if (err_exit == 3)
		err_exit++;
}

/*prints the given error message string err along with 
the system error message to stderr and exits with an error status*/
void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

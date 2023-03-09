/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:44:57 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/09 19:24:18 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_infile(char **argv, t_pipex *pipex)
{
	pipex->infile = open(argv[1], O_RDONLY, 0777);
	if (pipex->infile < 0)
	{
		if (access(argv[1], F_OK | R_OK))
			msg(strerror(errno), argv[1], 0);
	}
}

int	ft_outfile(char **argv, t_pipex *pipex)
{
	if (!access(argv[4], F_OK | W_OK))
		pipex->outfile = open(argv[4], O_WRONLY | O_TRUNC);
	else if (!access(argv[4], F_OK))
	{
		msg(strerror(errno), argv[4], 0);
		return (1);
	}
	else
		pipex->outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (0);
}

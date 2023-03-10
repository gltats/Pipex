/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:44:57 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/10 16:17:35 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*takes the first argument from the command line  
and attempts to open it using open with the O_RDONLY flag.*/
void	ft_infile(char **argv, t_pipex *pipex)
{
	pipex->infile = open(argv[1], O_RDONLY, 0777);
	if (pipex->infile < 0)
	{
		if (access(argv[1], F_OK | R_OK))
			msg(strerror(errno), argv[1], 0);
	}
}

/*takes the fourth argument from the command line, 
and first checks if the file already exists 
and has write permissions using access with the F_OK and W_OK flags. 
1. If the file exists and has write permissions,
	it is opened using open with the O_WRONLY and O_TRUNC flags. 
2. If the file exists but does not have write permissions, 
	the function calls the msg
3. If the file does not exist, it is created using open with 
	the O_CREAT, O_RDWR, and O_TRUNC flags, and opened for writing.*/
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

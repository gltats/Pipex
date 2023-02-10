/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:37:50 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/10 21:26:58 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//envp -> enviromental variable, example $PATH
int	main(int argc, char *argv[], char *envp[])
{
	int	ret;

	ret = pipex(argc, argv, *envp);
	if (ret == ERROR)
	{
		ft_putstr("Error occured while executing pipex.\n");
	}
	else if (ret == ERROR_INVALID_ARG)
	{
		ft_putstr("Invalid. 4 arguments expected: file1 cmd1 cmd2 file2\n");
	}
	return (ret);
}

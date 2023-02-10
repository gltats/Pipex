/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:43 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/10 21:04:51 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//\033[31m -> sets the color to red
//\e[0m -> restes the color
int	error_handling(int type_error)
{
	if (type_error == ERROR)
		perror("\033[31mERROR\e[0m");
	else if (type_error == ERROR_INVALID_ARG)
		ft_putstr("\033[31mError: incorrect number of arguments\n\e[0m");
	else if (type_error == ERROR_COMMAND_NOT_FOUND)
		ft_putstr("\033[31mError:Command not found\n\e[0m");
	else if (type_error == ERROR_EXECVE)
		perror("\033[31mExecve error:\n\e[0m");
	else if (type_error == ERROR_NO_TOKENS)
		ft_putstr("\033[31mError: No path\n\e[0m");
	return (type_error);
}

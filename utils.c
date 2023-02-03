/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:26:43 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/03 17:05:28 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//\033[31m -> sets the color to red
//\e[0m -> restes the color
int error_handling(int type_error)
{
	if(type_error == ERROR)
	{
		perror("\033[31mERROR\e[0m");
		return (1);
	}
	else if(type_error == ERROR_INVALID_ARG)
	{
		ft_putstr("\033[31mError: incorrect number of arguments\n\e[0m");
		return (1);
	}
	return(type_error);
}
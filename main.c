/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:37:50 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/01 17:28:26 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//envp -> enviromental variable, example $PATH

int main(int argc, char *argv[], char *envp[])
{
	pipex(argc, argv, envp);
	return(0);
}
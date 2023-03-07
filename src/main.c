/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:37:50 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/07 16:52:36 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//envp -> enviromental variable, example $PATH
int	main(int argc, char **argv, char **envp)
{
	int	ret;

	ret = pipex(argc, argv, *envp);
	return (ret);
}

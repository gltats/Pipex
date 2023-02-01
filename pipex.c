/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:03:42 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/01 12:05:28 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//envp -> enviromental variable, exaple $PATH
int main(int argc,char* argv[], char *envp[])
{
	int i;
	
	i = 0;
	printf("Program Name Is: %s\n",argv[0]);
	if (argc == 1)
		printf("No Extra Command Line Argument Passed Other Than Program Name\n");
	else if (argc == 2)
	{		
		printf("Amazing, your argv is -> %s\n",argv[1]);
	}
	return 0;
}
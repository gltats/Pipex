/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:06:28 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/02/08 13:58:29 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

#define ERROR 10
#define ERROR_WAITPID 20
#define ERROR_INVALID_ARG 30
#define ERROR_COMMAND_NOT_FOUND 40
#define ERROR_EXECVE 50

int pipex(int argc, char *argv[], char *envp[]);
#endif
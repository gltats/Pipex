/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgomes-l <tgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:18:15 by tgomes-l          #+#    #+#             */
/*   Updated: 2023/03/09 17:19:20 by tgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	put_spaces(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if ((args[i] == '\'') && (args[i + 1] != '\0'))
		{
			i++;
			while ((args[i] != '\'') && (args[i] != '\0'))
			{
				if (args[i] == 1)
					args[i] = ' ';
				i++;
			}
		}
		i++;
	}
}

static void	change_spaces(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (args[i] == '\'')
		{
			i++;
			while ((args[i] != '\'') && (args[i] != '\0'))
			{
				if (args[i] == ' ')
					args[i] = 1;
				i++;
			}
		}
		i++;
	}
}

static char	*remove_quotes(char *args)
{
	int		i;
	int		str_len;
	char	*new_str;

	i = 0;
	str_len = 0;
	while (args[i])
	{
		if (args[i] != '\'')
			str_len++;
		i++;
	}
	new_str = ft_calloc(str_len + 1, sizeof(char));
	i = 0;
	while (*args)
	{
		if (*args != '\'')
		{
			new_str[i] = *args;
			i++;
		}
		args++;
	}
	return (new_str);
}

void	parse_args(t_pipex *pipex, char *args)
{
	int		x;
	int		y;
	char	*tmp;

	y = 0;
	change_spaces(args);
	pipex->cmd_args = ft_split(args, ' ');
	while (pipex->cmd_args[y])
	{
		put_spaces(pipex->cmd_args[y]);
		x = 0;
		while (pipex->cmd_args[y][x])
		{
			if (pipex->cmd_args[y][x] == '\'')
			{
				tmp = pipex->cmd_args[y];
				pipex->cmd_args[y] = remove_quotes(pipex->cmd_args[y]);
				free(tmp);
				break ;
			}
			x++;
		}
		y++;
	}
}

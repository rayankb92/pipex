/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:58:22 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/19 00:05:06 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	set_path(t_data *data)
{
	int	i;

	i = -1;
	while (data->envp[++i])
		if (ft_strncmp(data->envp[i], "PATH", 4) == 0)
			data->paths = ft_split(data->envp[i] + 5, ':');
	return (1);
}

int	deal_parse(t_data *data, const char **argv, char **envp, int argc)
{
	if (argc != 5)
		return (0);
	data->prev_pipes = -1;
	data->in = (char *)argv[1];
	data->out = (char *)argv[argc - 1];
	if (!set_data(data, argv + 2, argc - 3, envp))
		return (0);
	set_path(data);
	iter_fork(data, argc - 3);
	return (1);
}

int	set_data(t_data *data, const char **argv, int argc, char **envp)
{
	int		i;

	i = -1;
	data->envp = envp;
	data->argv = (char **)argv;
	data->cmds = malloc(sizeof(t_cmd *) * (argc + 2));
	if (!data->cmds)
		return (0);
	while (++i < argc)
	{
		data->cmds[i] = malloc(sizeof(t_cmd));
		data->cmds[i]->args = ft_split(argv[i], ' ');
		if (!data->cmds[i] || !data->cmds[i]->args)
			return (0);
		data->cmds[i]->cmd = data->cmds[i]->args[0];
		if (ft_strchr(data->cmds[i]->cmd, '/'))
			data->cmds[i]->nopath = 1;
		else
			data->cmds[i]->nopath = 0;
		data->cmds[i]->ntm = 1;
	}
	data->cmds[i] = 0;
	return (1);
}

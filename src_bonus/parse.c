/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:58:22 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/19 02:01:19 by rferradi         ###   ########.fr       */
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

void	here_doc(t_data *data, const char **argv)
{
	char	*line;
	int		fd;
	char	*tmp;

	fd = open(data->in, O_RDWR | O_CREAT | O_TRUNC, 0666);
	while (1)
	{
		line = get_next_line(0, 1);
		tmp = ft_strjoin_chr(argv[2], '\n');
		if (!line || ft_strcmp(tmp, line) == 0)
			break ;
		ft_putstr_fd(line, fd);
		free(tmp);
		free(line);
	}
	free(tmp);
	free(line);
	get_next_line(0, 0);
	close (fd);
}

int	deal_parse(t_data *data, const char **argv, char **envp, int argc)
{
	data->prev_pipes = -1;
	data->in = (char *)argv[1];
	data->out = (char *)argv[argc - 1];
	data->nbcmd = argc - 3;
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		data->trunapp = O_APPEND;
		here_doc(data, argv);
		data->nbcmd = argc - 4;
		argv++;
	}
	if (!set_data(data, argv + 2, data->nbcmd, envp))
		return (0);
	set_path(data);
	iter_fork(data);
	return (1);
}

int	set_data(t_data *data, const char **argv, int nbccmd, char **envp)
{
	int		i;

	i = -1;
	data->envp = envp;
	data->argv = (char **)argv;
	data->cmds = malloc(sizeof(t_cmd *) * (nbccmd + 2));
	if (!data->cmds)
		return (0);
	while (++i < nbccmd)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:56:46 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/19 02:04:59 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	in_exec(t_data *data, int inout)
{
	int	opn;

	opn = ft_display_error(data, inout);
	if (opn < 0)
	{
		close(data->pipe[1]);
		close(data->pipe[0]);
		if (inout != 1)
			close(data->prev_pipes);
		ft_free(data);
		exit(1);
	}
	if (inout == 1)
	{
		dup2(opn, STDIN_FILENO);
		dup2(data->pipe[1], STDOUT_FILENO);
	}
	else
	{
		dup2(data->prev_pipes, STDIN_FILENO);
		dup2(opn, STDOUT_FILENO);
	}
	close(opn);
}

void	fork_exec(t_data *data, int argc, int i)
{
	if (i == 0)
		in_exec(data, 1);
	else if (i == (argc - 1))
		in_exec(data, 0);
	else
	{
		dup2(data->prev_pipes, STDIN_FILENO);
		dup2(data->pipe[1], STDOUT_FILENO);
	}
	close(data->pipe[1]);
	if (i != 0 && data->prev_pipes > 0)
		close(data->prev_pipes);
	close(data->pipe[0]);
	exec_cmd(data, data->cmds[i]);
}

void	iter_fork(t_data *data, int argc)
{
	int	i;
	int	pid;

	i = -1;
	while (++i < argc)
	{
		pipe(data->pipe);
		pid = fork();
		data->cmds[i]->pid = pid;
		if (pid == 0)
			fork_exec(data, argc, i);
		else
		{
			if (data->prev_pipes != -1)
				close(data->prev_pipes);
			data->prev_pipes = data->pipe[0];
			close(data->pipe[1]);
		}
	}
	close(data->pipe[0]);
}

int	ft_display_error(t_data *data, int inout)
{
	int	opn;

	if (inout == 1)
		opn = open(data->in, O_RDONLY, 0666);
	else
		opn = open(data->out, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (errno == 13)
		ft_printf("bash: %s: Permission denied\n", data->in);
	else if (opn < 0)
		ft_printf("bash: %s: No such file or directory\n", data->in);
	return (opn);
}

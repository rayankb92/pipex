/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:55:58 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/19 02:05:34 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_data *data, t_cmd *cmd)
{
	int		accs;
	int		j;
	char	*temp;

	j = -1;
	accs = -1;
	while (data->paths[++j])
	{
		if (cmd->nopath == 0)
		{
			temp = ft_strjoin(data->paths[j], cmd->cmd);
			accs = execve(temp, cmd->args, NULL);
			free(temp);
		}
		else
			accs = execve(cmd->cmd, cmd->args, NULL);
	}
	if (accs < 0)
	{
		if (errno == 13)
			ft_printf("bash: %s: Permission denied\n", cmd->cmd);
		else
			ft_printf("bash: %s: No such file or directory\n", cmd->cmd);
	}
}

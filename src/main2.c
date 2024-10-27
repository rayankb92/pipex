/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 01:20:28 by rferradi          #+#    #+#             */
/*   Updated: 2024/10/27 02:01:44 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
int error_msg(char *msg, char *name)
{
	if (!name)
	{
		ft_printf("pipex: %s", msg);
		return (0);
	}
	ft_printf("pipex: %s: %s", name, msg);
	exit(1);
}

int main(int argc, char const *argv[], char **envp)
{
	t_data	data;
	int		 	i;
	int			status;

	i = -1;
	status = 0;
	if ((argc != 5) || (!*envp) || (!deal_parse(&data, argv, envp, argc)))
		return (0);
	while (data.cmds[++i])
		waitpid(data.cmds[i]->pid, &status, 0);
	ft_free(&data);
	return (0);
}

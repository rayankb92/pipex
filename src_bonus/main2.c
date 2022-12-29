/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 01:20:28 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/19 01:59:33 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_msg(char *msg, char *name)
{
	if (!name)
	{
		ft_printf("pipex: %s", msg);
		return (0);
	}
	ft_printf("pipex: %s: %s", name, msg);
	exit(1);
}

int	main(int argc, char const *argv[], char **envp)
{
	t_data	data;
	int		i;
	int		status;

	i = -1;
	status = 0;
	data.argc = argc;
	data.trunapp = O_TRUNC;
	data.argv = (char **)argv;
	if ((argc < 6) || (!envp) || (!deal_parse(&data, argv, envp, argc)))
		return (0);
	while (data.cmds[++i])
		waitpid(data.cmds[i]->pid, &status, 0);
	if (data.trunapp == O_APPEND)
		unlink("here_doc");
	ft_free(&data);
	return (0);
}

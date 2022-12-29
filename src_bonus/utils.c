/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:54:15 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/17 23:33:39 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_free(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->paths[i])
		free(data->paths[i++]);
	free(data->paths);
	i = 0;
	while (data->cmds[i])
	{
		j = 0;
		while (data->cmds[i]->args[j])
			free(data->cmds[i]->args[j++]);
		j = 0;
		free(data->cmds[i]->args);
		free(data->cmds[i]);
		i++;
	}
	free(data->cmds);
	return (0);
}

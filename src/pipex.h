/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:10:37 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/19 02:04:30 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd	t_cmd;
typedef struct t_data
{
	t_cmd				**cmds;
	int					inf;
	int					outf;
	char				*in;
	char				*out;
	int					prev_pipes;
	char				*path;
	char				**paths;
	char				**envp;
	char				**argv;
	int					argc;
	int					pipe[2];
}						t_data;

struct					s_cmd
{
	t_data				*data;
	char				*cmd;
	char				**args;
	int					nopath;
	int					ntm;
	int					pid;
};
// Fork.c

void					in_exec(t_data *data, int inout);
void					fork_exec(t_data *data, int argc, int i);
void					iter_fork(t_data *data, int argc);
int						ft_display_error(t_data *data, int inout);
int						ft_display_error(t_data *data, int inout);

// Parse.c
int						set_path(t_data *data);
int						deal_parse(t_data *data, const char **argv, char **envp,
							int argc);
int						set_data(t_data *data, const char **argv, int argc,
							char **envp);

// exec.c
void					exec_cmd(t_data *data, t_cmd *cmd);

// utils.c
int						ft_free(t_data *data);

#endif
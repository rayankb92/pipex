/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:25:16 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/07 19:01:10 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_buffer(char *bufferleft, int fd)
{
	char	*temp;
	int		reader;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	reader = 1;
	while (reader != 0 && !ft_strchr_gnl(bufferleft, '\n'))
	{
		reader = read(fd, temp, BUFFER_SIZE);
		if (reader < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[reader] = 0;
		bufferleft = ft_strjoin_gnl(bufferleft, temp);
	}
	free(temp);
	return (bufferleft);
}

char	*cut_line(char *bufferleft)
{
	int		i;
	char	*newline;

	i = 0;
	if (!bufferleft[i])
		return (NULL);
	newline = malloc(sizeof(char *) * (count_line(bufferleft) + 2));
	if (!newline)
		return (NULL);
	while (bufferleft[i] && bufferleft[i] != '\n')
	{
		newline[i] = bufferleft[i];
		i++;
	}
	if (bufferleft[i] == '\n')
		newline[i++] = '\n';
	newline[i] = 0;
	return (newline);
}

char	*new_buff(char *bufferleft)
{
	int		i;
	int		j;
	char	*newbuff;

	i = 0;
	j = 0;
	while (bufferleft[i] && bufferleft[i] != '\n')
		i++;
	if (!bufferleft[i])
	{
		free(bufferleft);
		bufferleft = NULL;
		return (NULL);
	}
	newbuff = malloc(sizeof(char *) * (ft_strlen_gnl(bufferleft) - i + 1));
	if (!newbuff)
		return (NULL);
	while (bufferleft[i])
		newbuff[j++] = bufferleft[++i];
	newbuff[j] = 0;
	free(bufferleft);
	return (newbuff);
}

char	*get_next_line(int fd, int i)
{
	static char	*bufferleft;
	char		*line;

	if (!i)
	{
		free(bufferleft);
		return (NULL);
	}
	if (BUFFER_SIZE < 0 || fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	bufferleft = fill_buffer(bufferleft, fd);
	if (bufferleft == NULL)
	{
		free(bufferleft);
		return (NULL);
	}
	line = cut_line(bufferleft);
	bufferleft = new_buff(bufferleft);
	return (line);
}

// int main(int argc, char const *argv[])
// {
// 	// printf("laaa");
// 	int		opn;
// 	char	*buffer;
// 	int		i;

// 	i = -1;
// 	opn = open(argv[1], 0);
// 	while (++i <  atoi(argv[2]))
// 	{
// 		buffer = get_next_line(opn);
// 		printf("%s",buffer);
// 		free(buffer);
// 	}

// 	return 0;
// }

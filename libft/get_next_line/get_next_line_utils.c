/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:53:28 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/24 15:43:54 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr_gnl(char *str, char c)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

int	count_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;
	size_t	lens1;

	lens1 = ft_strlen_gnl(s1);
	res = malloc(sizeof(char) * (lens1 + ft_strlen_gnl(s2)) + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = -1;
	if (s1 != NULL)
	{
		while (s1[++j])
			res[j] = s1[j];
	}
	else
		j = 0;
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	free(s1);
	return (res);
}

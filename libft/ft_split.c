/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:32:31 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/08 20:16:58 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**cleaner(char ***str, int len)
{
	while (--len >= 0)
		free((*str)[len]);
	free(*str);
	return (0);
}

int	countword(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	*put_in_tab(const char *s, int *i, char c)
{
	static int	j;
	int			index;
	char		*res;

	j = 0;
	index = 0;
	while (s[*i] == c && s[*i])
		(*i)++;
	while (s[*i + j] != c && s[*i + j])
		j++;
	res = malloc(sizeof(char) * j + 1);
	if (!res)
		return (NULL);
	while (index < j)
	{
		res[index++] = s[*i];
		(*i)++;
	}
	res[index] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		lenword;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	lenword = countword(s, c);
	res = malloc(sizeof(char *) * (lenword + 1));
	if (!res)
		return (NULL);
	while (i < lenword)
	{
		res[i] = put_in_tab(s, &j, c);
		if (res[i] == NULL)
			return (cleaner(&res, i));
		i++;
	}
	res[i] = 0;
	return (res);
}

// int main(int argc, char const *argv[])
// {
// 	// printf("%i\n", countword("salut-mec-bien-ou-quoi", 'z'));
// 	int i = 0;
// 	char **res;
// 	res = ft_split("       salut mec bien o u quoi", ' ');
// 	if (res)
// 		while(res[i])
// 		{
// 			printf("res[%i] = '%s'\n",i, res[i]);
// 			i++;
// 		}
// 	cleaner(&res, i);
// 	return 0;
// }

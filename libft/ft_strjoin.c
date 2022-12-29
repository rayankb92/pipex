/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:31:44 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/16 20:27:09 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (!res || !s1 || !s2)
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
		res[j] = s1[j];
	i = 0;
	res[j++] = '/';
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

char	*ft_strjoin_chr(char const *s1, char c)
{
	int		j;
	char	*res;

	res = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!res)
		return (NULL);
	j = -1;
	while (s1[++j])
		res[j] = s1[j];
	res[j++] = c;
	res[j] = '\0';
	return (res);
}

// int main(int argc, char const *argv[])
// {
// 	char *res;
// 	res = ft_strjoin("suffixe ", "prefixe");
// 	printf("%s\n", res);
// 	return 0;
// }

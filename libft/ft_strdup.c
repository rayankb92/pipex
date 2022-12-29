/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:58:17 by rferradi          #+#    #+#             */
/*   Updated: 2022/09/21 03:21:49 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		i;

	i = -1;
	res = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!res)
		return (0);
	while (s[++i])
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

// int main(int argc, char const *argv[])
// {
// 	char	test[] = "lorem ipsum dolor sit amet";
// 	char	*res;
// 	res = ft_strdup(test);
// 	printf("%s\n", res);
// 	return 0;
// }

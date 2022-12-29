/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:10:25 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/08 20:11:08 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen || !s)
		return (ft_strdup(""));
	if (start + len > slen)
		len = slen - start;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while ((s[start]) && (i < len))
		res[i++] = s[start++];
	res[i] = 0;
	return (res);
}

	// temp = ft_strdup(res);
	// return (temp);
// int main(int argc, char const *argv[])
// {
// 	char *res;
// 	res = ft_substr("tripouille", 0, 4200);
// 	printf("%s\n", res);
// 	free(res);
// 	return 0;
// }
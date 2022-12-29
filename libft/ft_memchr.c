/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:17:26 by rferradi          #+#    #+#             */
/*   Updated: 2022/09/21 02:21:29 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = -1;
	str = (unsigned char *)s;
	while (++i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)s + i);
	}
	return (NULL);
}

// int main(int argc, char const *argv[])
// {
// 	const char ok[10] = "salut";
// 	const char ok2[10] = "salut";
// 	char *res = "ok";
// 	char *res1 = "ok";
// 	char *res2 = "ok";
// 	char *res3 = "ok";
// 	char *res4 = "ok";
// 	char *res5 = "ok";
// 	char *res6 = "ok";

// int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
// printf("%c\n", (unsigned char)tab[7]);
// printf("%s", (char *)ft_memchr(tab, -1, 7));
// // 	res1 = (char *)ft_memchr("bonjour", 'b', 4);
// // 	res2 = ft_memchr("bonjour", 'o', 7);
// // 	res3 = ft_memchr("bonjourno", 'n', 2);
// // 	res4 = ft_memchr("bonjour", 'j', 6);
// // 	res5 = ft_memchr("bonjour", 's', 7);
// // 	printf("bonjour = %s\nonjour = %s\nnull = %s\njour = 
// // %s\nnul = %s\n", res1, res2, res3, res4, res5);

// 	return 0;
// }

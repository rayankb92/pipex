/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:46:08 by rferradi          #+#    #+#             */
/*   Updated: 2022/09/19 19:00:05 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)str;
	while (i < n)
	{
		res[i] = 0;
		i++;
	}
}

// int main(int argc, char const *argv[])
// {
// 	char str[] = "salut";
// 	printf("%s\n", str);
// 	ft_bzero(str, 1);
// 	printf("%c\n", str[1]);
// 	return 0;
// }

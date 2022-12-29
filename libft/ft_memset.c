/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:21:56 by rferradi          #+#    #+#             */
/*   Updated: 2022/09/19 18:59:47 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*res;
	size_t	i;

	i = 0;
	res = s;
	while (i < n)
		res[i++] = (unsigned char)c;
	return (res);
}

// int	main(void)
// {
// 	char ok[] = "s";
// 	char ok2[] = "s";

// 	printf("FT = %s\n", (char *)ft_memset(ok, 'R',  3));
// 	printf("VR = %s\n", (char *)memset(ok2, 'R',  3));
// 	return 0;
// }

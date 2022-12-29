/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:55:43 by rferradi          #+#    #+#             */
/*   Updated: 2022/09/21 02:41:55 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	i = 0;
	str2 = (unsigned char *)s2;
	str = (unsigned char *)s1;
	while (i++ < n)
	{
		if (*str != *str2)
			return ((int)*str - (int)*str2);
		str++;
		str2++;
	}
	return (0);
}

// int main(int argc, char const *argv[])
// {
// 	const void *ok = "a";
// 	const void *ok2 = "b";
// 	printf("FT = %d\n", ft_memcmp(ok, ok2, 1));
// 	printf("VR = %d\n", memcmp(ok, ok2 , 1));

// 	return 0;
// }

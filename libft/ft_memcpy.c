/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:50:30 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/08 20:01:48 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*res;
	const char	*source;

	i = -1;
	if (!dest && !src)
		return (NULL);
	res = dest;
	source = src;
	while (++i < n)
		res[i] = source[i];
	return (res);
}

// int main(void)
// {
// 	const char tamr[10] = "mamanya";
// 	char tonpr[10] = "okok";
// 	const char tamr1[10] = "mamanya";
// 	char tonpr1[10] = "okok";
// 	// ft_memcpy(tonpr, tamr, 3);
// 	// memcpy(tonpr1, tamr1, 3);
// 	printf("FT = %s\n", (char *)ft_memcpy(tonpr, tamr, 9));
// 	printf("VR = %s\n", (char *)memcpy(tonpr1, tamr1, 9));
// 	return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:02:27 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/08 20:03:06 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	len = ft_strlen(dest);
	if (len >= size)
		return (size + ft_strlen(src));
	while ((src[i]) && (len < size - 1))
	{
		dest[len++] = src[i++];
	}
	dest[len] = '\0';
	return (len + ft_strlen(&src[i]));
}

// int main()
// {
// 	const char src[] = "salut";
// 	char *dest;
// 	const char src2[] = "salut";
// 	char *dest2;
// 	dest = malloc(sizeof(char) * 15);
// 	dest2 = malloc(sizeof(char) * 15);
// 		memset(dest, 'r', 15);
// 		memset(dest2, 'r', 15);
// 		dest[10] = 'a';
// 		dest2[10] = 'a';
// 	printf("FT: return %ld DEST = %s\n", 
// 		ft_strlcat(dest, "lorem", 15), dest);
// 	printf("VR: return %ld DEST = %s\n", 
// 		strlcat(dest2, "lorem", 15), dest2);
// 	return 0;
// }
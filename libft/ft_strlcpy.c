/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:12:34 by rferradi          #+#    #+#             */
/*   Updated: 2022/09/22 23:02:05 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	if (!size)
		return (len);
	while ((i < size - 1) && (src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (len);
}

// int main(int argc, char const *argv[])
// {
// 	const char src[] = "salut";
// 	char dest[10];
// 	const char src2[] = "salut";
// 	char dest2[10];
// 	printf("FT: return %ld DEST = %s\n", 
// 		ft_strlcpy(dest, src, 3), dest);
// 	printf("VR: return %ld DEST = %s\n", 
// 		strlcpy(dest2, src2, 3), dest2);
// 	return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:46:50 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/08 20:33:24 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ladest;
	char	*lasrc;

	i = -1;
	ladest = (char *)dest;
	lasrc = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
		while (n-- > 0)
			ladest[n] = lasrc[n];
	else
		while (++i < n)
			ladest[i] = lasrc[i];
	return (dest);
}

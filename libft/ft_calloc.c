/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:39:35 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/10 14:27:32 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elem, size_t elemsize)
{
	void		*res;

	if (elem > MAXSIZE || elemsize > MAXSIZE)
		return (NULL);
	res = malloc(elem * elemsize);
	if (!res)
		return (NULL);
	if (res)
		ft_bzero(res, elem * elemsize);
	return (res);
}

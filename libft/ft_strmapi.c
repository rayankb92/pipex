/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:43:18 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/08 20:18:00 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	i = -1;
	res = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (s[++i])
		res[i] = f(i, s[i]);
	res[i] = 0;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:10:24 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/07 16:01:35 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		ft_putchar_fd(s[i], fd);
	if (fd == 2)
		return (0);
	else
		return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaystrstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:16:44 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/19 02:18:09 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	display_strstr(char **str, char *def)
{
	int	i;

	i = -1;
	(void)def;
	ft_printf("{");
	while (str[++i])
		ft_printf("%s, ", str[i]);
	ft_printf("}\n");
}

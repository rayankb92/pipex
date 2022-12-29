/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:44:27 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/07 12:19:36 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i]) && ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' ')))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= 57 && str[i] >= 48)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

// int main(int argc, char *argv[])
// {
// 	printf("%i\n", ft_atoi(argv[1]));
// 	printf("%i\n", atoi(argv[1]));
// 	return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 23:58:00 by rferradi          #+#    #+#             */
/*   Updated: 2022/09/26 01:37:28 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	itoa_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	itostr(char **res, int n, int index)
{
	long long int	nb;

	nb = (long long int)n;
	if (nb < 0)
	{
		(*res)[0] = '-';
		nb *= -1;
	}
	if (nb > 9)
		itostr(res, (nb / 10), index - 1);
	(*res)[index] = (nb % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = itoa_len(n);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = 0;
	itostr(&res, n, --len);
	return (res);
}
// int main(int argc, char const *argv[])
// {
// 	char *res;

// 	res = ft_itoa(-12);
// 	printf("%s\n", res);
// 	return 0;
// }
